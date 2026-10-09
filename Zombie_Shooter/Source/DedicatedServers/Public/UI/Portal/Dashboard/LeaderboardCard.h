// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LeaderboardCard.generated.h"

class URichTextBlock;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ULeaderboardCard : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetPlayerInformation(const FString& Username, const int32 Kills) const;


private:
	UPROPERTY()
	TObjectPtr<URichTextBlock> UserName;

	UPROPERTY()
	TObjectPtr<URichTextBlock> ZombieKills;
	
	
};
