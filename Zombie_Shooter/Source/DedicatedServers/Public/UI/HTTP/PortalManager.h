#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include "PortalManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBroadcastJoinGameSessionMessage, const FString&, StatusMessage, bool, bShouldResetJoinGameButton);

UCLASS()
class DEDICATEDSERVERS_API UPortalManager : public UHTTPRequestManager
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable)
	FBroadcastJoinGameSessionMessage BroadcastJoinGameSessionMessage;
	
	void JoinGameSession();
	
	void LaunchSinglePlayerGame();
	
private:
	void FindOrCreateGameSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void CreatePlayerSession_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
	FString GetUniquePlayerID() const;
	
	void HandleGameSessionStatus(const FString& Status, const FString& SessionID);
	
	void TryCreatePlayerSession(const FString& PlayerID, const FString& GameSessionID);
	
	void FocusPlayerControlerBackToScreen();
	
	FTimerHandle CreateSessionTimer;
};