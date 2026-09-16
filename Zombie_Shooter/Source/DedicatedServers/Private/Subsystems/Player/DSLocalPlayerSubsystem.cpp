// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Player/DSLocalPlayerSubsystem.h"
#include "UI/HTTP/PortalManager.h"

void UDSLocalPlayerSubsystem::InitTokens(const FDSAuthenticationResult& Result, UPortalManager* Manager)
{
	AuthenticationResult = Result;

	PortalManager = Manager;

	SetRefreshTokenTimer();
}

void UDSLocalPlayerSubsystem::SetRefreshTokenTimer()
{
	UWorld* World = GetWorld();
	if (IsValid(World))
	{
		FTimerDelegate RefreshDelegate;

		RefreshDelegate.BindLambda([this]()
			{
				PortalManager->RefreshToken(AuthenticationResult.RefreshToken);
			});
		
		World->GetTimerManager().SetTimer(RefreshTimer, RefreshDelegate, TokenRefreshInterval, false);
	}
}

void UDSLocalPlayerSubsystem::UpdateTokens(const FString& AccessToken, const FString& IdToken)
{
	AuthenticationResult.AccessToken = AccessToken;
	AuthenticationResult.IdToken = IdToken;

	AuthenticationResult.Dump();

	SetRefreshTokenTimer();
}