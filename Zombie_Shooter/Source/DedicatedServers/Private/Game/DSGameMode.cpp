// Fill out your copyright notice in the Description page of Project Settings.

#include "DedicatedServers/Public/Game/DSGameMode.h"

DEFINE_LOG_CATEGORY(DedicatedServersLog)

ADSGameMode::ADSGameMode()
{
	
}

void ADSGameMode::BeginPlay()
{
	Super::BeginPlay();

#if WITH_GAMELIFT
	InitGameLift();
#endif

}

void ADSGameMode::InitGameLift()
{
	UE_LOG(DedicatedServersLog, Log, TEXT("Initializing the Gamelift Server"));

	//Gets the GameLift SDK Module
	FGameLiftServerSDKModule* GameLiftSDKModule = &FModuleManager::LoadModuleChecked<FGameLiftServerSDKModule>(FName("GameLiftServerSDK"));

	//Defines the Server Params for a Gamelift Anywhere Fleet. These are not needed for a Gamelift Managed EC2 Fleet.
	FServerParameters ServerParameters;
	SetServerParameters(ServerParameters);

	//InitSDK establishes a Local connection with GameLift's ahent to enable further communication.
	//Use InitSDK(ServerParameters) for a Gamelift Anywhere Fleet.
	//Use InitSDK() for a GameLift Manager EC2 Fleet.
	GameLiftSDKModule->InitSDK(ServerParameters);

	//Implement Callback function onGameSession
	//Gamelift sends a game session activation request to the game server
	//and passes a game session object with the game properties and other settings.
	//Here is where a game server takes action based on the game session object.
	//When the game server is ready to recieve incoming player connections,
	//it invokes the server SDK call ActivateGameSession().
	auto onGameSession = [=](Aws::GameLift::Server::Model::GameSession gameSession)
		{
			FString gameSessionId = FString(gameSession.GetGameSessionId());
			UE_LOG(DedicatedServersLog, Log, TEXT("GameSession Initializing: %s"), *gameSessionId);
			GameLiftSDKModule->ActivateGameSession();
		};

	ProcessParameters.OnStartGameSession.BindLambda(onGameSession);

	//Implement Callback function onProcessTerminate
	//Gamelift invokes this callback before shutting down the instance hosting this game server.
	//It gives the game server a chance to save its state, communication with services, etc..
	//and initiate shutdown. When the game is ready to shutdown, it invokes the
	//server SDK call ProcessEnding() to tell Gamelift it is shutting down.
	auto onProcessTerminate = [=]()
		{
			UE_LOG(DedicatedServersLog, Log, TEXT("Game Game Server Process is terminating"));
			GameLiftSDKModule->ProcessEnding();
		};

	ProcessParameters.OnTerminate.BindLambda(onProcessTerminate);

	//Implement Callback function onHealthCheck
	//Gamelift invokes this callback approximately every 60 seconds.
	//A game server might want to check the health of dependencies, etc.
	//Then it returns health status true if healthy, false otherwise.
	//The game server must respond within 60 seconds, or Gamelift records 'false'.
	//In this example, the game server always reports healthy.

	auto onHealthCheck = [=]()
		{
			UE_LOG(DedicatedServersLog, Log, TEXT("Performing Health Check."));
			return true;
		};

	ProcessParameters.OnHealthCheck.BindLambda(onHealthCheck);

	int32 Port = FURL::UrlConfig.DefaultPort;
	ParseCommandLinePort(Port);
	ProcessParameters.port = Port;

	//Here, the game server tells Gamelift where to find game session Log files.
	//At the end of a game session, Gamelift uploads everything in the specified
	//Location and stores it in the cloud for access later
	TArray<FString> LogFiles;
	LogFiles.Add(TEXT("Zombie_Shooter/Saved/Logs/Zombie_Shooter.log"));
	ProcessParameters.logParameters = LogFiles;

	//The game server called ProcessReady() to tell Gamelift it's ready to host game sessions.
	UE_LOG(DedicatedServersLog, Log, TEXT("Calling Process Ready"));
	GameLiftSDKModule->ProcessReady(ProcessParameters);
}

void ADSGameMode::SetServerParameters(FServerParameters& OutParams)
{
	//AuthToken returned from the "AWS GameLift get-compute-auth-token" API. Note this will expire and require a new call to the API 15 minutes
	if (FParse::Value(FCommandLine::Get(), TEXT("-authtoken="), OutParams.m_authToken))
	{
		UE_LOG(DedicatedServersLog, Log, TEXT("AUTH_TOKEN: %s"), *OutParams.m_authToken);
	}

	//The Host/compute-name of the GameLift Anywhere Instance
	if (FParse::Value(FCommandLine::Get(), TEXT("-hostid="), OutParams.m_hostId))
	{
		UE_LOG(DedicatedServersLog, Log, TEXT("HOST_ID: %s"), *OutParams.m_authToken);
	}

	//The Anywhere Fleet ID
	if (FParse::Value(FCommandLine::Get(), TEXT("-fleetid="), OutParams.m_fleetId))
	{
		UE_LOG(DedicatedServersLog, Log, TEXT("FLEET_ID: %s"), *OutParams.m_fleetId);
	}

	//The WebSocket URL (GameLiftServiceSdkEndpoint).
	if (FParse::Value(FCommandLine::Get(), TEXT("-websocketurl="), OutParams.m_webSocketUrl))
	{
		UE_LOG(DedicatedServersLog, Log, TEXT("WEBSOCKET_URL: %s"), *OutParams.m_webSocketUrl);
	}

	//The PID of the Running Process
	OutParams.m_processId = FString::Printf(TEXT("%d"), GetCurrentProcessId());
	UE_LOG(DedicatedServersLog, Log, TEXT("PID: %s"), *OutParams.m_processId);
}

void ADSGameMode::ParseCommandLinePort(int32& OutPort)
{
	//The game server gets ready to report that it is ready to host game sessions.
	//and that it will listen on port 7777 for incoming player connections.
	TArray<FString> CommandLineTokens;
	TArray<FString> CommandLineSwitches;
	FCommandLine::Parse(FCommandLine::Get(), CommandLineTokens, CommandLineSwitches);
	for (const FString& Switch : CommandLineSwitches)
	{
		FString Key;
		FString Value;
		if (Switch.Split("=", &Key, &Value))
		{
			if (Key.Equals(TEXT("port"), ESearchCase::IgnoreCase))
			{
				OutPort = FCString::Atoi(*Value);
				return;
			}
		}
	}
}