// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"
#include "UI/Widgets/RichTextButton.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "Components/RichTextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "UI/Portal/SignIn/ConfirmationSignUpPage.h"
#include "UI/Portal/SignIn/SignInPage.h"
#include "UI/Portal/SignIn/SignUpPage.h"
#include "UI/Portal/SignIn/SuccessConfirmedPage.h"


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

	check(SignInButtonTest);
	SignInButtonTest->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignInPage);

	check(SignUpButtonTest);
	SignUpButtonTest->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignUpPage);

	check(ConfirmarionSignUpButtonTest);
	ConfirmarionSignUpButtonTest->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowConfirmationSignUpPage);

	check(SuccessConfirmedButtonTest);
	SuccessConfirmedButtonTest->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSuccessConfirmPage);
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

void USignInOverlay::ShowSignInPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(SignInPage));

	WidgetSwitcher->SetActiveWidget(SignInPage);
}

void USignInOverlay::ShowSignUpPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(SignUpPage));

	WidgetSwitcher->SetActiveWidget(SignUpPage);
}

void USignInOverlay::ShowConfirmationSignUpPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(ConfirmationSignUpPage));

	WidgetSwitcher->SetActiveWidget(ConfirmationSignUpPage);
}

void USignInOverlay::ShowSuccessConfirmPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(SuccessConfirmPage));

	WidgetSwitcher->SetActiveWidget(SuccessConfirmPage);
}