// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/APITest/TestRecordStats.h"

#include "UI/GameStats/GameStatsManager.h"
#include "Components/Button.h"
#include "UI/HTTP/HTTPRequestTypes.h"

void UTestRecordStats::NativeConstruct()
{
	Super::NativeConstruct();

	GameStatsManager = NewObject<UGameStatsManager>(this, GameStatsManagerClass);
	ButtonRecordMatchStats->OnClicked.AddDynamic(this, &UTestRecordStats::RecordMatchStatsButtonClicked);
}

void UTestRecordStats::RecordMatchStatsButtonClicked()
{
	check(GameStatsManager);

	FDSRecordMatchStatsInput RecordMatchStats;
	RecordMatchStats.username = TEXT("testuser1");
	RecordMatchStats.matchStats.kills = 10;

	GameStatsManager->RecordMatchStats(RecordMatchStats);
}