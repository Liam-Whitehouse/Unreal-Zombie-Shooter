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


void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(PortalManagerClass);
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	
	check(IsValid(LaunchSinglePlayerWidget));
	check(IsValid(LaunchSinglePlayerWidget->ButtonRoot));
	LaunchSinglePlayerWidget->ButtonRoot->OnClicked.AddDynamic(this, &USignInOverlay::OnLaunchSinglePlayerButtonClicked);

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