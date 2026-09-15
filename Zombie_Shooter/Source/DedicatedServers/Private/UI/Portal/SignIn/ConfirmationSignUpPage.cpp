// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/ConfirmationSignUpPage.h"
#include "Components/EditableTextBox.h"
#include "Components/RichTextBlock.h"


void UConfirmationSignUpPage::ClearTextBoxes()
{
	ConfirmationCodeTextBox->SetText(FText::GetEmpty());
	TextBlockStatusMessage->SetText(FText::GetEmpty());
	TextBlockDestination->SetText(FText::GetEmpty());
}