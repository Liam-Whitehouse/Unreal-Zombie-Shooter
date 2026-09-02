// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "FleetID.generated.h"

class URichTextBlock;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UFleetID : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> FleetIDRichText;
};
