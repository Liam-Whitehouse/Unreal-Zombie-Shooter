// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/SignUpPage.h"

#include "Components/EditableTextBox.h"
#include "Components/RichTextBlock.h"
#include "UI/Widgets/RichTextButton.h"

void USignUpPage::NativeConstruct()
{
	Super::NativeConstruct();

	UserNameTextBox->OnTextChanged.AddDynamic(this, &USignUpPage::UpdateSignUpButtonState);

	PasswordTextBox->OnTextChanged.AddDynamic(this, &USignUpPage::UpdateSignUpButtonState);

	ConfirmPasswordTextBox->OnTextChanged.AddDynamic(this, &USignUpPage::UpdateSignUpButtonState);

	EmailTextBox->OnTextChanged.AddDynamic(this, &USignUpPage::UpdateSignUpButtonState);

	SignUpButton->SetIsEnabled(false);
}

void USignUpPage::UpdateSignUpButtonState(const FText& Text)
{
	const bool bIsUsernameValid = !UserNameTextBox->GetText().ToString().IsEmpty();
	const bool bArePasswordsTheSame = PasswordTextBox->GetText().ToString() == ConfirmPasswordTextBox->GetText().ToString();
	const bool bIsValidEmail = IsValidEmail(EmailTextBox->GetText().ToString());
	const bool bIsPasswordLong = PasswordTextBox->GetText().ToString().Len() >= 8;

	//Is a "Strong" Password?
	FString StatusMessage;
	const bool bIsStrongPassword = IsStrongPassword(PasswordTextBox->GetText().ToString(), StatusMessage);

	if (bIsStrongPassword == false)
	{
		TextBlockStatusMessage->SetText(FText::FromString(StatusMessage));
	}
	else if (bIsUsernameValid == false)
	{
		TextBlockStatusMessage->SetText(FText::FromString(TEXT("Please enter a valid Username")));
	}
	else if (bArePasswordsTheSame == false)
	{
		TextBlockStatusMessage->SetText(FText::FromString(TEXT("Confirm Password and Password must match!")));
	}
	else if (bIsValidEmail == false)
	{
		TextBlockStatusMessage->SetText(FText::FromString(TEXT("Please enter a valid Email.")));
	}
	else if (bIsPasswordLong == false)
	{
		TextBlockStatusMessage->SetText(FText::FromString(TEXT("Password needs to be 8 Characters Long")));
	}

	SignUpButton->SetIsEnabled(bIsStrongPassword && bIsUsernameValid && bArePasswordsTheSame && bIsValidEmail && bIsPasswordLong);
}

bool USignUpPage::IsValidEmail(const FString& Email)
{
	const FRegexPattern EmailPattern(TEXT(R"((^[^\s@]+@[^\s@]+\.[^\s@]{2,}$))"));

	FRegexMatcher Matcher(EmailPattern, Email);

	return Matcher.FindNext();
}

bool USignUpPage::IsStrongPassword(const FString& Password, FString& StatusMessage)
{
	//Contains at least 1 number
	const FRegexPattern NumberPattern(TEXT(R"(\d)"));

	//Contains at least 1 special character
	const FRegexPattern SpecialCharPattern(TEXT(R"([^\w\s])"));

	//Contains at least 1 capital letter
	const FRegexPattern UppercasePattern(TEXT(R"([A-Z])"));

	//Contains at least 1 lower case letter
	const FRegexPattern LowercasePattern(TEXT(R"([a-z])"));

	FRegexMatcher NumberMatcher(NumberPattern, Password);
	FRegexMatcher SpecialCharMatcher(SpecialCharPattern, Password);
	FRegexMatcher UpperCaseMatcher(UppercasePattern, Password);
	FRegexMatcher LowercaseMatcher(LowercasePattern, Password);

	if (NumberMatcher.FindNext() == false)
	{
		StatusMessage = TEXT("Password must contain at least 1 Number.");
		return false;
	}

	if (SpecialCharMatcher.FindNext() == false)
	{
		StatusMessage = TEXT("Password must contain at least 1 Special Character.");
		return false;
	}

	if (UpperCaseMatcher.FindNext() == false)
	{
		StatusMessage = TEXT("Password must contain at least 1 Uppercase Character.");
		return false;
	}

	if (LowercaseMatcher.FindNext() == false)
	{
		StatusMessage = TEXT("Password must contain at least 1 Lowercase Character.");
		return false;
	}

	return true;
}