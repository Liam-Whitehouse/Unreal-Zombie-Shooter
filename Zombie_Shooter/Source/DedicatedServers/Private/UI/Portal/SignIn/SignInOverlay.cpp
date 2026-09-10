// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"
#include "UI/Widgets/RichTextButton.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "Components/RichTextBlock.h"


void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(PortalManagerClass);
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->JoinGameButton));
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	
	JoinGameWidget->JoinGameButton->OnClicked.AddDynamic(this, &USignInOverlay::OnJoinGameButtonClicked);
	
	check(IsValid(LaunchSinglePlayerWidget));
	check(IsValid(LaunchSinglePlayerWidget->ButtonRoot));
	LaunchSinglePlayerWidget->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnLaunchSinglePlayerButtonClicked);

	check(IsValid(QuitGameWidget));
	check(IsValid(QuitGameWidget->ButtonRoot));
	QuitGameWidget->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnQuitGameButtonClicked);
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

void USignInOverlay::OnQuitGameButtonClicked()
{
	APlayerController* SpecificPlayer = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	check(IsValid(SpecificPlayer));

	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Type::Quit, true);
}

void USignInOverlay::OnLaunchSinglePlayerButtonClicked()
{
	check(IsValid(PortalManager));
	
	PortalManager->LaunchSinglePlayerGame();
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
