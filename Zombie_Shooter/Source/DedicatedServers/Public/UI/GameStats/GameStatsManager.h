// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include <UI/HTTP/HTTPRequestTypes.h>
#include "GameStatsManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRetrieveLeaderboard, const TArray<FDSLeaderboardItem>&, Leaderboard);

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UGameStatsManager : public UHTTPRequestManager
{
	GENERATED_BODY()
	
	
public:

	void RecordMatchStats(const FDSRecordMatchStatsInput& RecordMatchStatsInput);
	
	void UpdateLeaderboard(const FString& Player);

	void RetrieveLeaderboard();

	UPROPERTY()
	FOnRetrieveLeaderboard OnRetrieveLeaderboard;

	UPROPERTY()
	FOnAPIRequestSucceeded OnUpdateLeaderboardSucceeded;

private:

	void UpdateLeaderboard_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void RetrieveLeaderboard_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};