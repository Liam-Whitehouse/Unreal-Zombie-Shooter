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

void UDashboardOverlay::NativeConstruct()
{
	check(PortalManagerClass);
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);

	check(GamePageButton);
	check(GamePageButton->ButtonRoot);
	GamePageButton->ButtonRoot->OnClicked.AddDynamic(this, &UDashboardOverlay::OnGameButtonClicked);

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

		return;
	}

	SignOutButton->SetVisibility(ESlateVisibility::Collapsed);
	SignInButton->SetVisibility(ESlateVisibility::Visible);
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
	PortalManager->QuitGame();
}

void UDashboardOverlay::OnSignInButtonClicked()
{
	PortalManager->EnterSignUp();
}

void UDashboardOverlay::OnSignOutButtonClicked()
{
	PortalManager->SignOut();
}