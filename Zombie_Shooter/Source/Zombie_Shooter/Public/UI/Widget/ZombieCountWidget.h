// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieCountWidget.generated.h"

class URichTextBlock;

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieCountWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> ZombieText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> KillNumText;

protected:

	virtual void NativeConstruct() override;

private:

	void UpdateZombieKillCount(int32 NewKillCount);

	int32 CurrentZombieCount;
};