// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/SignInPage.h"
#include "UI/Widgets/RichTextButton.h"
#include "Components/RichTextBlock.h"
#include "Components/EditableTextBox.h"
#include "UI/HTTP/HTTPRequestTypes.h"

void USignInPage::UpdateStatusMessage(const FString& Message, bool bShouldResetWidgets)
{
	TextBlockStatusMessage->SetText(FText::FromString(Message));

	if (bShouldResetWidgets)
	{
		SignInButton->SetIsEnabled(true);
	}
	else
	{
		SignInButton->SetIsEnabled(false);
	}
}

void USignInPage::ClearTextBoxes()
{
	UserNameTextBox->SetText(FText::GetEmpty());
	PasswordTextBox->SetText(FText::GetEmpty());
	TextBlockStatusMessage->SetText(FText::FromString(HTTPStatusMessages::EnterInCredentials));
}

void USignInPage::NativeConstruct()
{
	Super::NativeConstruct();
	UserNameTextBox->OnTextChanged.AddDynamic(this, &USignInPage::UpdateSignInButtonState);
	PasswordTextBox->OnTextChanged.AddDynamic(this, &USignInPage::UpdateSignInButtonState);

	SignInButton->SetIsEnabled(false);

	UpdateStatusMessage(HTTPStatusMessages::EnterInCredentials, false);
}

void USignInPage::UpdateSignInButtonState(const FText& Text)
{
	bool bIsUserInformationFilled = !UserNameTextBox->GetText().IsEmpty() && !PasswordTextBox->GetText().IsEmpty();
	
	UpdateStatusMessage(HTTPStatusMessages::EnterInCredentials, bIsUserInformationFilled);
}