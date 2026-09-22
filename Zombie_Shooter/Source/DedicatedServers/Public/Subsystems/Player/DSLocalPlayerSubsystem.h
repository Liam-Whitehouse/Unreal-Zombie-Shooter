// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include <UI/HTTP/HTTPRequestTypes.h>
#include "DSLocalPlayerSubsystem.generated.h"

class IPortalManagement;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UDSLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	void InitTokens(const FDSAuthenticationResult& Result, TScriptInterface<IPortalManagement> PortalManager);
	void SetRefreshTokenTimer();
	void UpdateTokens(const FString& AccessToken, const FString& IdToken);

	void SetUsername(const FString& PlayerUsername);

	const FString& GetUserName();

	const FDSAuthenticationResult& GetDSAuthenticalResults();

	void SetIsLoggedIn(bool bLoggedIn);
	bool GetIsLoggedIn();

private:
	UPROPERTY()
	FDSAuthenticationResult AuthenticationResult;

	UPROPERTY()
	TScriptInterface<IPortalManagement> PortalManagementInterface;

	//This is roughly 75% of an hour.
	float TokenRefreshInterval = 2700.0f;
	FTimerHandle RefreshTimer;

	FString Username;

	bool bIsLoggedIn = false;
};
