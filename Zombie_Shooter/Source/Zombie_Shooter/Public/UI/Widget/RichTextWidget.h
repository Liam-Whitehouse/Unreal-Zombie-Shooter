// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RichTextWidget.generated.h"

class URichTextBlock;

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API URichTextWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> TextWidget;
};
