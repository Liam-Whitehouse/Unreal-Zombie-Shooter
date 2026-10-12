// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/LeaderboardCard.h"
#include "Components/RichTextBlock.h"

void ULeaderboardCard::SetPlayerInformation(const FString& Username, const int32 Kills, const int32 place) const
{
	FString PlaceText = TEXT("Rank: ") + FString::FromInt(place);
	Place->SetText(FText::FromString(PlaceText));

	UserName->SetText(FText::FromString(Username));

	FString KillsText = TEXT("Zombie Kills: ") + FString::FromInt(Kills);
	ZombieKills->SetText(FText::FromString(KillsText));
}