// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Player/DSLocalPlayerSubsystem.h"
#include "UI/HTTP/PortalManager.h"

void UDSLocalPlayerSubsystem::InitTokens(const FDSAuthenticationResult& Result, TScriptInterface<IPortalManagement> PortalManager)
{
	AuthenticationResult = Result;

	PortalManagementInterface = PortalManager;

	SetRefreshTokenTimer();
}

void UDSLocalPlayerSubsystem::SetRefreshTokenTimer()
{
	UWorld* World = GetWorld();
	if (IsValid(World))
	{
		if (IsValid(PortalManagementInterface.GetObject()))
		{
			FTimerDelegate RefreshDelegate;

			RefreshDelegate.BindLambda([this]()
				{
					PortalManagementInterface->RefreshTokens(AuthenticationResult.RefreshToken);
				});
		
			World->GetTimerManager().SetTimer(RefreshTimer, RefreshDelegate, TokenRefreshInterval, false);
		}
	}
}

void UDSLocalPlayerSubsystem::UpdateTokens(const FString& AccessToken, const FString& IdToken)
{
	AuthenticationResult.AccessToken = AccessToken;
	AuthenticationResult.IdToken = IdToken;

	AuthenticationResult.Dump();

	SetRefreshTokenTimer();
}

const FDSAuthenticationResult& UDSLocalPlayerSubsystem::GetDSAuthenticalResults()
{
	return AuthenticationResult;
}

void UDSLocalPlayerSubsystem::SetIsLoggedIn(bool bLoggedIn)
{
	bIsLoggedIn = bLoggedIn;
}

bool UDSLocalPlayerSubsystem::GetIsLoggedIn()
{
	return bIsLoggedIn;
}
