// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/ConfirmationSignUpPage.h"
#include "Components/EditableTextBox.h"
#include "Components/RichTextBlock.h"
#include "UI/Widgets/RichTextButton.h"


void UConfirmationSignUpPage::ClearTextBoxes()
{
	ConfirmationCodeTextBox->SetText(FText::GetEmpty());
	TextBlockStatusMessage->SetText(FText::GetEmpty());
	TextBlockDestination->SetText(FText::GetEmpty());
}

void UConfirmationSignUpPage::UpdateStatusMessage(const FString& Message, bool bShouldResetWidgets)
{
	TextBlockStatusMessage->SetText(FText::FromString(Message));

	if (bShouldResetWidgets)
	{
		ConfirmButton->SetIsEnabled(true);
	}
}

void UConfirmationSignUpPage::NativeConstruct()
{
	Super::NativeConstruct();

	ConfirmationCodeTextBox->OnTextChanged.AddDynamic(this, &UConfirmationSignUpPage::UpdateConfirmedButtonState);

	ConfirmButton->SetIsEnabled(false);
}

void UConfirmationSignUpPage::UpdateConfirmedButtonState(const FText& Text)
{
	const FRegexPattern SixDigitsPattern(TEXT(R"(^\d{6}$)"));

	FRegexMatcher SxDigitMather(SixDigitsPattern, Text.ToString());

	const bool bValidConfimationCode = SxDigitMather.FindNext();

	ConfirmButton->SetIsEnabled(bValidConfimationCode);
	if (bValidConfimationCode)
	{
		TextBlockStatusMessage->SetText(FText::FromString(""));
		
		return;
	}
	
	TextBlockStatusMessage->SetText(FText::FromString("Please enter the six digit verification code."));
}