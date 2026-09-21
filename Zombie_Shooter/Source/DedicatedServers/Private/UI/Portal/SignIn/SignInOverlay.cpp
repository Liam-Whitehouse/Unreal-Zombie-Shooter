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
#include "Components/EditableTextBox.h"
#include "UI/HTTP/PortalManager.h"
#include "UI/Portal/Dashboard/WBP_DevelopersPage.h"
#include "Subsystems/Player/DSLocalPlayerSubsystem.h"


void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(SignOutButton);
	SignOutButton->SetVisibility(ESlateVisibility::Collapsed);

	check(PlayGameButton);
	check(PlayGameButton->ButtonRoot);
	PlayGameButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnPlayNowClicked);

	check(DevelopersButton);
	check(DevelopersButton->ButtonRoot);
	DevelopersButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnShowDevelopersClicked);

	check(PortalManagerClass);
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	
	check(IsValid(QuitGameWidget));
	check(IsValid(QuitGameWidget->ButtonRoot));
	QuitGameWidget->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnQuitGameButtonClicked);

	check(SignInPage);
	check(SignInPage->SignInButton);
	SignInPage->SignInButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::SignInButtonClicked);
	SignInPage->SignUpButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignUpPage);
	PortalManager->SignInStatusMessageMessageDelegate.AddDynamic(SignInPage, &USignInPage::UpdateStatusMessage);

	check(SignUpPage);
	check(SignUpPage->SignUpButton);
	SignUpPage->SignUpButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::SignUpButtonClicked);
	SignUpPage->BackButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignInPage);

	PortalManager->SignUpStatusMessageDelegate.AddDynamic(SignUpPage, &USignUpPage::UpdateStatusMessage);
	PortalManager->OnAPIRequestSucceeded.AddDynamic(this, &USignInOverlay::OnSignUpSucceeded);
	PortalManager->OnConfirmSucceeded.AddDynamic(this, &USignInOverlay::OnConfirmSucceeded);
	PortalManager->ConfirmStatusMessageDelegate.AddDynamic(ConfirmationSignUpPage, &UConfirmationSignUpPage::UpdateStatusMessage);

	check(ConfirmationSignUpPage);
	check(ConfirmationSignUpPage->ConfirmButton);
	ConfirmationSignUpPage->ConfirmButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ConfirmButtonClicked);
	ConfirmationSignUpPage->BackButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignUpPage);

	check(SuccessConfirmPage);
	check(SuccessConfirmPage->OkButton);
	SuccessConfirmPage->OkButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignInPage);

	check(LeaderboardsButton);
	check(LeaderboardsButton->ButtonRoot);
	LeaderboardsButton->ButtonRoot->SetIsEnabled(false);

	check(SignInButton);
	check(SignInButton->ButtonRoot);
	SignInButton->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::ShowSignInPage);
}

void USignInOverlay::OnQuitGameButtonClicked()
{
	check(PortalManager);
	PortalManager->QuitGame(GetAccessToken());
}

FString USignInOverlay::GetAccessToken() const
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

void USignInOverlay::OnPlayNowClicked()
{
	PortalManager->EnterOfflineMode();
}

void USignInOverlay::OnShowDevelopersClicked()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(DevelopersPage));

	SignInPage->ClearTextBoxes();
	SignUpPage->ClearTextBoxes();

	WidgetSwitcher->SetActiveWidget(DevelopersPage);
}

void USignInOverlay::AdjustWidgets()
{
	check(PortalManager);

	if (PortalManager->IsPlayerLoggedIn())
	{
		SignOutButton->SetVisibility(ESlateVisibility::Visible);
		SignInButton->SetVisibility(ESlateVisibility::Collapsed);
		LeaderboardsButton->ButtonRoot->SetIsEnabled(true);
		return;
	}

	SignOutButton->SetVisibility(ESlateVisibility::Collapsed);
	SignInButton->SetVisibility(ESlateVisibility::Visible);
	LeaderboardsButton->ButtonRoot->SetIsEnabled(false);
}

void USignInOverlay::ShowSignInPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(SignInPage));

	SignInPage->ClearTextBoxes();

	WidgetSwitcher->SetActiveWidget(SignInPage);
}

void USignInOverlay::ShowSignUpPage()
{
	check(IsValid(WidgetSwitcher));
	check(IsValid(SignUpPage));

	SignUpPage->ClearTextBoxes();

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

void USignInOverlay::SignInButtonClicked()
{
	const FString Username = SignInPage->UserNameTextBox->GetText().ToString();
	const FString Password = SignInPage->PasswordTextBox->GetText().ToString();

	PortalManager->SignIn(Username, Password);
}

void USignInOverlay::SignUpButtonClicked()
{
	SignUpPage->SignUpButton->SetIsEnabled(false);

	const FString Username = SignUpPage->UserNameTextBox->GetText().ToString();
	const FString Password = SignUpPage->PasswordTextBox->GetText().ToString();
	const FString Email = SignUpPage->EmailTextBox->GetText().ToString();

	PortalManager->SignUp(Username, Password, Email);
}

void USignInOverlay::ConfirmButtonClicked()
{
	const FString Code = ConfirmationSignUpPage->ConfirmationCodeTextBox->GetText().ToString();
	ConfirmationSignUpPage->ConfirmButton->SetIsEnabled(false);
	PortalManager->ConfirmationCode(Code);
}

void USignInOverlay::OnSignUpSucceeded()
{
	SignUpPage->ClearTextBoxes();

	ConfirmationSignUpPage->TextBlockDestination->SetText(FText::FromString(PortalManager->LastSignUpResponse.CodeDeliveryDetails.Destination));

	ShowConfirmationSignUpPage();
}

void USignInOverlay::OnConfirmSucceeded()
{
	ConfirmationSignUpPage->ClearTextBoxes();
	ShowSuccessConfirmPage();
}