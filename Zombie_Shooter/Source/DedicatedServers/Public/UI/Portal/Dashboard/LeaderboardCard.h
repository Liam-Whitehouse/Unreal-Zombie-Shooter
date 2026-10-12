// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LeaderboardCard.generated.h"

class URichTextBlock;
class UHorizontalBox;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ULeaderboardCard : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetPlayerInformation(const FString& Username, const int32 Kills, const int32 place) const;


private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> UserName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> ZombieKills;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> Place;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> LeaderboardCardBox;
	
};