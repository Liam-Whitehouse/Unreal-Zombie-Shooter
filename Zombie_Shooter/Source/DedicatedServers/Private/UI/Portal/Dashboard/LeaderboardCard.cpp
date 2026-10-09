// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/LeaderboardCard.h"
#include "Components/RichTextBlock.h"

void ULeaderboardCard::SetPlayerInformation(const FString& Username, const int32 Kills) const
{
	UserName->SetText(FText::FromString(Username));
	ZombieKills->SetText(FText::AsNumber(Kills));
}