// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignUpPage.generated.h"

class UEditableTextBox;
class URichTextButton;
class URichTextBlock;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API USignUpPage : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> UserNameTextBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> PasswordTextBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> ConfirmPasswordTextBox;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> EmailTextBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignUpButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> BackButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockStatusMessage;

	UFUNCTION()
	void UpdateStatusMessage(const FString& Message, bool bShouldResetWidgets);

	void ClearTextBoxes();

protected:

	virtual void NativeConstruct() override;

private:

	UFUNCTION()
	void UpdateSignUpButtonState(const FText& Text);

	bool IsValidEmail(const FString& Email);

	bool IsStrongPassword(const FString& Password, FString& StatusMessage);
};