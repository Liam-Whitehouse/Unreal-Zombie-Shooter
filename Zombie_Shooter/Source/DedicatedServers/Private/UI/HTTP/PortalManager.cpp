// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HTTP/PortalManager.h"

#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "Data/API/APIData.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Interfaces/IHttpResponse.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

void UPortalManager::JoinGameSession()
{
	BroadcastJoinGameSessionMessage.Broadcast(TEXT("Searching for Game Session..."), false);
	
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::FindOrCreateGameSession_Response);
	
	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameSessionsAPI::FindOrCreateGameSession);
	
	//Sets the Request URL
	Request->SetURL(APIUrl);
	
	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));
	
	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	
	Request->ProcessRequest();
}

void UPortalManager::LaunchSinglePlayerGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("MainLevel")));
	
	FocusPlayerControlerBackToScreen();
}

void UPortalManager::FindOrCreateGameSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response,
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

void UPortalManager::CreatePlayerSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response,
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
		
		FocusPlayerControlerBackToScreen();
		
		const FString IPAndPort = PlayerSession.IpAddress + TEXT(":") + FString::FromInt(PlayerSession.Port);
		const FName Address = FName(*IPAndPort);
		UGameplayStatics::OpenLevel(GetWorld(), Address);
	}
}

FString UPortalManager::GetUniquePlayerID() const
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

void UPortalManager::HandleGameSessionStatus(const FString& Status, const FString& SessionID)
{
	if (Status.Equals(TEXT("ACTIVE")))
	{
		BroadcastJoinGameSessionMessage.Broadcast(TEXT("Found Active Game Session. Creating a Player Session"), false);
		
		TryCreatePlayerSession(GetUniquePlayerID(), SessionID);
	}
	else if (Status.Equals(TEXT("ACTIVATING")))
	{
		FTimerDelegate CreateSessionDelegate;
		
		CreateSessionDelegate.BindUObject(this, &UPortalManager::JoinGameSession);
		
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

void UPortalManager::TryCreatePlayerSession(const FString& PlayerID, const FString& GameSessionID)
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::CreatePlayerSession_Response);
	
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

void UPortalManager::FocusPlayerControlerBackToScreen()
{
	APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (IsValid(LocalPlayerController))
	{
		FInputModeGameOnly InputModeData;
		LocalPlayerController->SetInputMode(InputModeData);
		LocalPlayerController->SetShowMouseCursor(false);
	}
}
