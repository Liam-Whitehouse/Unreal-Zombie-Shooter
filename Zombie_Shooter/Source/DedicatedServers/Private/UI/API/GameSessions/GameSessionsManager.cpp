// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/API/GameSessions/GameSessionsManager.h"

#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "Data/API/APIData.h"
#include "GameFramework/PlayerState.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/GameplayStatics.h"
#include <UI/HTTP/HTTPRequestTypes.h>
#include "Subsystems/Player/DSLocalPlayerSubsystem.h"

void UGameSessionsManager::JoinGameSession()
{
	BroadcastJoinGameSessionMessage.Broadcast(TEXT("Searching for Game Session..."), false);

	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UGameSessionsManager::FindOrCreateGameSession_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameSessionsAPI::FindOrCreateGameSession);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	UDSLocalPlayerSubsystem* PlayerSubsystem = GetDSLocalPlayerSubSystem();
	if (IsValid(PlayerSubsystem))
	{
		Request->SetHeader(TEXT("Authorization"), PlayerSubsystem->GetDSAuthenticalResults().AccessToken);
	}

	Request->ProcessRequest();
}

void UGameSessionsManager::FindOrCreateGameSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		BroadcastJoinGameSessionMessage.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			BroadcastJoinGameSessionMessage.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
		}

		FDSGameSession GameSession;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &GameSession);

		HandleGameSessionStatus(GameSession.Status, GameSession.GameSessionId);
	}
}

void UGameSessionsManager::CreatePlayerSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		BroadcastJoinGameSessionMessage.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			BroadcastJoinGameSessionMessage.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
		}

		FDSPlayerSession PlayerSession;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &PlayerSession);

		PlayerSession.Dump();

		FocusPlayerControllerBackToScreen();

		const FString IPAndPort = PlayerSession.IpAddress + TEXT(":") + FString::FromInt(PlayerSession.Port);
		const FName Address = FName(*IPAndPort);
		UGameplayStatics::OpenLevel(GetWorld(), Address);
	}
}

FString UGameSessionsManager::GetUniquePlayerID() const
{
	APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (IsValid(LocalPlayerController))
	{
		APlayerState* LocalPlayerState = LocalPlayerController->GetPlayerState<APlayerState>();
		if (IsValid(LocalPlayerState) && LocalPlayerState->GetUniqueId().IsValid())
		{
			const FString UniqueId = FString(TEXT("Player_")) + FString::FromInt(LocalPlayerState->GetUniqueID());
			return UniqueId;
		}
	}

	return FString();
}

void UGameSessionsManager::HandleGameSessionStatus(const FString& Status, const FString& SessionID)
{
	if (Status.Equals(TEXT("ACTIVE")))
	{
		BroadcastJoinGameSessionMessage.Broadcast(TEXT("Found Active Game Session. Creating a Player Session"), false);

		TryCreatePlayerSession(GetUniquePlayerID(), SessionID);
	}
	else if (Status.Equals(TEXT("ACTIVATING")))
	{
		FTimerDelegate CreateSessionDelegate;

		CreateSessionDelegate.BindUObject(this, &UGameSessionsManager::JoinGameSession);

		APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
		if (IsValid(LocalPlayerController))
		{
			LocalPlayerController->GetWorldTimerManager().SetTimer(CreateSessionTimer, CreateSessionDelegate, 0.5f, false);
		}
	}
	else
	{
		BroadcastJoinGameSessionMessage.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}
}

void UGameSessionsManager::TryCreatePlayerSession(const FString& PlayerID, const FString& GameSessionID)
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UGameSessionsManager::CreatePlayerSession_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameSessionsAPI::CreatePlayerSession);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	TMap<FString, FString> Params =
	{
		{TEXT("playerId"), PlayerID},
		{TEXT("gameSessionId"), GameSessionID}
	};

	const FString Content = SerializedJsonContent(Params);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}