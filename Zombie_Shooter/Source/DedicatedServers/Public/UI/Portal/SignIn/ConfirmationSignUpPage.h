// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConfirmationSignUpPage.generated.h"

class UEditableTextBox;
class URichTextButton;
class URichTextBlock;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UConfirmationSignUpPage : public UUserWidget
{
	GENERATED_BODY()
	
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> ConfirmationCodeTextBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> ConfirmButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> BackButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockStatusMessage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockDestination;
};
