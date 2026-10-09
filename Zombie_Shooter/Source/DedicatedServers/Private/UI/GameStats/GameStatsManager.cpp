// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameStats/GameStatsManager.h"
#include "JsonObjectConverter.h"
#include "HttpModule.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "Data/API/APIData.h"
#include "Interfaces/IHttpResponse.h"
#include "DedicatedServers/DedicatedServers.h"
#include "GameplayTags/DedicatedServersTags.h"

void UGameStatsManager::RecordMatchStats(const FDSRecordMatchStatsInput& RecordMatchStatsInput)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	FJsonObjectConverter::UStructToJsonObject(FDSRecordMatchStatsInput::StaticStruct(), &RecordMatchStatsInput, JsonObject.ToSharedRef());

	FString JsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FDSRecordMatchStatsInput::StaticStruct(), &RecordMatchStatsInput, JsonString);

	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameStatsAPI::RecordMatchStats);

	Request->SetURL(APIUrl);
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);
	Request->ProcessRequest();
}

void UGameStatsManager::UpdateLeaderboard(const FString& Player)
{
	check(APIData);

	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameStatsAPI::UpdateLeaderboard);
	Request->OnProcessRequestComplete().BindUObject(this, &UGameStatsManager::UpdateLeaderboard_Response);

	Request->SetURL(APIUrl);
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");


	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TArray<TSharedPtr<FJsonValue>> PlayerIDJsonArray;

	PlayerIDJsonArray.Add(MakeShareable(new FJsonValueString(Player)));

	JsonObject->SetArrayField(TEXT("playerIds"), PlayerIDJsonArray);

	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UGameStatsManager::RetrieveLeaderboard()
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::GameStatsAPI::RetrieveLeaderboard);
	Request->OnProcessRequestComplete().BindUObject(this, &UGameStatsManager::RetrieveLeaderboard_Response);

	Request->SetURL(APIUrl);
	Request->SetVerb("GET");
	Request->SetHeader("Content-Type", "application/json");
	Request->ProcessRequest();
}

void UGameStatsManager::UpdateLeaderboard_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		OnUpdateLeaderboardSucceeded.Broadcast();
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			return;
		}
	}

	OnUpdateLeaderboardSucceeded.Broadcast();
}

void UGameStatsManager::RetrieveLeaderboard_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogDedicatedServers, Error, TEXT("Failed to retrieve leaderboard."));
		return;
	}

	TArray<FDSLeaderboardItem> LeaderboardItems;
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>>* LeaderboardJsonArray;
		if (JsonObject->TryGetArrayField(TEXT("Leaderboard"), LeaderboardJsonArray))
		{
			for (const TSharedPtr<FJsonValue>& ItemValue : *LeaderboardJsonArray)
			{
				TSharedPtr<FJsonObject> ItemObject = ItemValue->AsObject();
				if (ItemObject.IsValid())
				{
					FDSLeaderboardItem Item;
					if (FJsonObjectConverter::JsonObjectToUStruct(ItemObject.ToSharedRef(), &Item))
					{
						LeaderboardItems.Add(Item);
					}
					else
					{
						UE_LOG(LogDedicatedServers, Error, TEXT("Failed to parse leaderboard item."));
					}
				}
			}
		}
	}

	OnRetrieveLeaderboard.Broadcast(LeaderboardItems);
}