// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ZombieCountWidget.h"
#include "Components/RichTextBlock.h"
#include <PlayerState/ZombiePlayerState.h>

void UZombieCountWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UZombieCountWidget::UpdateZombieKillCount(int32 NewKillCount)
{
	if (!IsValid(KillNumText))
	{
		UE_LOG(LogTemp, Warning, TEXT("Kill Num Text is Invalid."));

		return;
	}

	KillNumText->SetText(FText::AsNumber(NewKillCount));
}