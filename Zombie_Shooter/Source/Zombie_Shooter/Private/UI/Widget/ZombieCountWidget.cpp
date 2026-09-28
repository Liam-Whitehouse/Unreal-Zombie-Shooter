// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ZombieCountWidget.h"
#include "Components/RichTextBlock.h"

void UZombieCountWidget::NativeConstruct()
{
}

void UZombieCountWidget::UpdateZombieKillCount(int32 NewKillCount)
{
	KillNumText->SetText(FText::AsNumber(NewKillCount));
}