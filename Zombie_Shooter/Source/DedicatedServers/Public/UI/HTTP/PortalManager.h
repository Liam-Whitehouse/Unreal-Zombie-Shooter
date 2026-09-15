#pragma once

#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include "PortalManager.generated.h"

UCLASS()
class DEDICATEDSERVERS_API UPortalManager : public UHTTPRequestManager
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FAPIStatusMessage SignUpStatusMessageDelegate;

	void SignIn(const FString& Username, const FString& Password);
	void SignUp(const FString& Username, const FString& Password, const FString& Email);
	void ConfirmationCode(const FString& ConfirmationCode);

	void LaunchSinglePlayerGame();

private:
	void SignUp_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};