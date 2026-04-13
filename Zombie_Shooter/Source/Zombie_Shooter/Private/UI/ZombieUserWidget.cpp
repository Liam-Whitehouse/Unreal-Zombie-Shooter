// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ZombieUserWidget.h"

void UZombieUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	WidgetControllerSet();
}

void UZombieUserWidget::BindCallbackToDependencies()
{
}

void UZombieUserWidget::BroadcastInitialValues()
{
}