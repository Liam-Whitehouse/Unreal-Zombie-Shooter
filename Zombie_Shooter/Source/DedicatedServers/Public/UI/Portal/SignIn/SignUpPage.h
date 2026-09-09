// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignUpPage.generated.h"

class UEditableTextBox;
class UButton;
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
	TObjectPtr<UButton> SignUpButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BackButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockStatusMessage;
};
