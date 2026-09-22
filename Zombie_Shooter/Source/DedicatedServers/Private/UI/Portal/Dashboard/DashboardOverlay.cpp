// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "UI/Widgets/RichTextButton.h"
#include "Components/WidgetSwitcher.h"
#include "UI/Portal/Dashboard/WBP_DevelopersPage.h"
#include "UI/Portal/Dashboard/GamePage.h"
#include "UI/Portal/Dashboard/LeaderboardsPage.h"
#include "UI/HTTP/PortalManager.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include "UI/API/GameSessions/JoinGame.h"
#include "Subsystems/Player/DSLocalPlayerSubsystem.h"

void UDashboardOverlay::NativeConstruct()
{
	check(PortalManagerClass);
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);

	check(GamePageButton);
	check(GamePageButton->ButtonRoot);
	GamePageButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnGameButtonClicked);

	check(Gamepage);
	check(Gamepage->SoloPlayButton);
	Gamepage->SoloPlayButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::LaunchSinglePlayer);

	check(SignInButton);
	check(SignInButton->ButtonRoot);
	SignInButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnSignInButtonClicked);

	check(SignOutButton);
	check(SignOutButton->ButtonRoot);
	SignOutButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnSignOutButtonClicked);
	SignOutButton->SetVisibility(ESlateVisibility::Collapsed);

	check(LeaderboardButton);
	check(LeaderboardButton->ButtonRoot);
	LeaderboardButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnLeaderboardButtonClicked);

	check(DevelopersButton);
	check(DevelopersButton->ButtonRoot);
	DevelopersButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnDevelopersButtonClicked);

	check(QuitGameButton);
	check(QuitGameButton->ButtonRoot);
	QuitGameButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnQuitGameButtonClicked);
}

void UDashboardOverlay::AdjustWidgets()
{
	check(PortalManager);

	if (PortalManager->IsPlayerLoggedIn())
	{
		SignOutButton->SetVisibility(ESlateVisibility::Visible);
		SignInButton->SetVisibility(ESlateVisibility::Collapsed);
		LeaderboardButton->ButtonRoot->SetIsEnabled(true);
		Gamepage->MultiplayerJoinGame->SetIsEnabled(true);

		return;
	}

	SignOutButton->SetVisibility(ESlateVisibility::Collapsed);
	SignInButton->SetVisibility(ESlateVisibility::Visible);
	Gamepage->MultiplayerJoinGame->SetIsEnabled(false);
	LeaderboardButton->ButtonRoot->SetIsEnabled(false);
}

void UDashboardOverlay::OnGameButtonClicked()
{
	check(WidgetSwitcher);

	WidgetSwitcher->SetActiveWidget(Gamepage);
}

void UDashboardOverlay::OnLeaderboardButtonClicked()
{
	check(WidgetSwitcher);

	WidgetSwitcher->SetActiveWidget(LeaderboardsPage);
}

void UDashboardOverlay::OnDevelopersButtonClicked()
{
	check(WidgetSwitcher);

	WidgetSwitcher->SetActiveWidget(DevelopersPage);
}

void UDashboardOverlay::OnQuitGameButtonClicked()
{
	check(PortalManager);
	PortalManager->QuitGame(GetAccessToken());
}

FString UDashboardOverlay::GetAccessToken() const
{
	check(PortalManager);
	UDSLocalPlayerSubsystem* PlayerSubSystem = PortalManager->GetDSLocalPlayerSubSystem();
	if (IsValid(PlayerSubSystem))
	{
		const FDSAuthenticationResult& AuthResults = PlayerSubSystem->GetDSAuthenticalResults();

		return AuthResults.AccessToken;
	}

	return FString();
}

void UDashboardOverlay::OnSignInButtonClicked()
{
	PortalManager->EnterSignUp();
}

void UDashboardOverlay::OnSignOutButtonClicked()
{
	check(PortalManager);
	if (GetAccessToken().IsEmpty())
	{
		return;
	}

	PortalManager->SignOut(GetAccessToken());
}

void UDashboardOverlay::LaunchSinglePlayer()
{
	check(PortalManager);
	PortalManager->LaunchSinglePlayerGame();
}