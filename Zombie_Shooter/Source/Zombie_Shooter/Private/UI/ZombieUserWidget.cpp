// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ZombieUserWidget.h"
#include "UI/ZombieAttributeWidgetController.h"

void UZombieUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	WidgetControllerSet();
}

void UZombieUserWidget::SetupAIWidgetController(const FZombieWidgetControllerParams& Params)
{
	if (AIWidgetControllerClass == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Forgot to assign AI WidgetControllerClass dmubass"));
		return;
	}
	AIWidgetController = NewObject<UZombieAttributeWidgetController>(this, AIWidgetControllerClass);
	if (AIWidgetController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Widget Controller Class has not been set on the Widget itself"));
		return;
	}

	AIWidgetController->SetupWidgetControllerParams(Params);
	AIWidgetController->BindCallbackToDependencies();

	SetWidgetController(AIWidgetController);
}

UObject* UZombieUserWidget::GetWidgetController()
{
	return WidgetController;
}

void UZombieUserWidget::BindCallbackToDependencies()
{
}

void UZombieUserWidget::BroadcastInitialValues()
{
}