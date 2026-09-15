// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include "GameSessionsManager.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UGameSessionsManager : public UHTTPRequestManager
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FAPIStatusMessage BroadcastJoinGameSessionMessage;

	void JoinGameSession();

private:

	void FindOrCreateGameSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void CreatePlayerSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	FString GetUniquePlayerID() const;

	void HandleGameSessionStatus(const FString& Status, const FString& SessionID);
	void TryCreatePlayerSession(const FString& PlayerID, const FString& GameSessionID);

	FTimerHandle CreateSessionTimer;
};
