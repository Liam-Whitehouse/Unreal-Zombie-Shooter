// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RichTextButton.generated.h"

class URichTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API URichTextButton : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ConfirmButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextBlockStatusMessage;
	
};
