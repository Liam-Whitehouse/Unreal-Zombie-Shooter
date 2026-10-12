// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LeaderboardsPage.generated.h"

class URichTextBlock;
class UScrollBox;
class ULeaderboardCard;
struct FDSLeaderboardItem;


/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ULeaderboardsPage : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
	void PopulateLeaderboard(TArray<FDSLeaderboardItem>& Leaderboard);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> LeaderboardTitle;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UScrollBox> LeaderboardScrollBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ULeaderboardCard> LeaderboardCardClass;

protected:

private:

	void CalculateLeaderboardPlaces(TArray<FDSLeaderboardItem>& OutLeaderboard);

};
