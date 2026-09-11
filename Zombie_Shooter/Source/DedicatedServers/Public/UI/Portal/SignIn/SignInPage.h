// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignInPage.generated.h"

class UEditableTextBox;
class URichTextButton;
class URichTextBlock;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API USignInPage : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> UserNameTextBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> PasswordTextBox;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignInButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockStatusMessage;
};
