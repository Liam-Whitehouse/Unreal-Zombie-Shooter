// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/APITest/TestRecordStats.h"
#include "UI/GameStats/GameStatsManager.h"
#include "Components/Button.h"

void UTestRecordStats::NativeConstruct()
{
	Super::NativeConstruct();

	GameStatsManager = NewObject<UGameStatsManager>(this, GameStatsManagerClass);
	ButtonRecordMatchStats->OnClicked.AddDynamic(this, &UTestRecordStats::RecordMatchStatsButtonClicked);
}

void UTestRecordStats::RecordMatchStatsButtonClicked()
{
	FDSRecordMatchStatsInput RecordMatchStats;


}