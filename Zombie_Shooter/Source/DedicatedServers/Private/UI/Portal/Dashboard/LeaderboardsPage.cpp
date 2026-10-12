// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/LeaderboardsPage.h"
#include "Components/ScrollBox.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "UI/Portal/Dashboard/LeaderboardCard.h"

void ULeaderboardsPage::PopulateLeaderboard(TArray<FDSLeaderboardItem>& Leaderboard)
{
	LeaderboardScrollBox->ClearChildren();

	CalculateLeaderboardPlaces(Leaderboard);

	for (const FDSLeaderboardItem& Item : Leaderboard)
	{
		ULeaderboardCard* LeaderboardCard = CreateWidget<ULeaderboardCard>(this, LeaderboardCardClass);
		if (!IsValid(LeaderboardCard))
		{
			UE_LOG(LogTemp, Warning, TEXT("Leaderboard Card was Invalid for item: [%s] in [%s]"), *Item.username, *GetName());
			return;
		}

		LeaderboardCard->SetPlayerInformation(Item.username, Item.kills, Item.place);

		LeaderboardScrollBox->AddChild(LeaderboardCard);
	}
}

void ULeaderboardsPage::CalculateLeaderboardPlaces(TArray<FDSLeaderboardItem>& OutLeaderboard)
{
	//This sorts is so the player with the most match wins will be "first" in the Leaderboard.
	OutLeaderboard.Sort([](const FDSLeaderboardItem& A, const FDSLeaderboardItem& B)
		{
			return A.kills > B.kills;
		});

	//Assign places based on kills.
	int32 CurrentPosition = 1;
	for (int32 i = 0; i < OutLeaderboard.Num(); i++)
	{
		if (i > 0 && OutLeaderboard[i].kills == OutLeaderboard[i - 1].kills)
		{
			//If the kills are the same as the previous item, they share the same place.
			OutLeaderboard[i].place = OutLeaderboard[i - 1].place;
		}
		else
		{
			//If wins are different, assign current position as the place
			OutLeaderboard[i].place = CurrentPosition;
		}
		
		CurrentPosition++;
	}
}