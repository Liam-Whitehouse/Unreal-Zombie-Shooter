#pragma once

#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include <UI/HTTP/HTTPRequestTypes.h>
#include "UI/Portal/Interface/PortalManagement.h"
#include "PortalManager.generated.h"

UCLASS()
class DEDICATEDSERVERS_API UPortalManager : public UHTTPRequestManager, public IPortalManagement
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable)
	FAPIStatusMessage SignUpStatusMessageDelegate;

	UPROPERTY(BlueprintAssignable)
	FAPIStatusMessage ConfirmStatusMessageDelegate;

	UPROPERTY(BlueprintAssignable)
	FAPIStatusMessage SignInStatusMessageMessageDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnAPIRequestSucceeded OnAPIRequestSucceeded;

	UPROPERTY(BlueprintAssignable)
	FOnAPIRequestSucceeded OnConfirmSucceeded;

	void SignIn(const FString& Username, const FString& Password);
	void SignUp(const FString& Username, const FString& Password, const FString& Email);
	void ConfirmationCode(const FString& ConfirmationCode);

	void SetPlayerLoggedInStatus(bool bLoggedIn);
	void EnterOfflineMode();
	void EnterSignUp();
	void SignOut(const FString& AccessToken);
	void QuitGame(const FString& AccessToken);

	void LaunchSinglePlayerGame();

	bool IsPlayerLoggedIn();
	void SetPlayerTokens(FDSAuthenticationResult& Result);

	//Portal Management Function
	virtual void RefreshTokens(const FString& RefreshToken) override;

	FDSSignUpResponse LastSignUpResponse;

	FString LastUsername;

private:
	void CloseApplication();

	void SignUp_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void SignIn_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void Confirm_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void RefreshToken_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void SignOut_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void QuitGame_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};