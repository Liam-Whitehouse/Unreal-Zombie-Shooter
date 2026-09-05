// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"

void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(PortalManagerClass);
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->JoinGameButton));
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	
	
	JoinGameWidget->JoinGameButton->OnClicked.AddDynamic(this, &USignInOverlay::OnJoinGameButtonClicked);
}

void USignInOverlay::OnJoinGameButtonClicked()
{
	check(IsValid(PortalManager));
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->JoinGameButton));
	
	PortalManager->BroadcastJoinGameSessionMessage.AddDynamic(this, &USignInOverlay::UpdateJoinGameStatusMessage);
	
	PortalManager->JoinGameSession();
	
	JoinGameWidget->JoinGameButton->SetIsEnabled(false);
	
	
}

void USignInOverlay::UpdateJoinGameStatusMessage(const FString& Message, bool bResetJoinGameButton)
{
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->JoinGameButton));
	JoinGameWidget->SetStatusMessage(Message);

	if (bResetJoinGameButton)
	{
		JoinGameWidget->JoinGameButton->SetIsEnabled(true);
	}
}