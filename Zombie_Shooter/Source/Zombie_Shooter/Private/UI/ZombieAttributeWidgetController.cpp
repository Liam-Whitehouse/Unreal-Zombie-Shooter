// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ZombieAttributeWidgetController.h"
#include "AbilitySystem/ZombieAttributeSet.h"

void UZombieAttributeWidgetController::SetupWidgetControllerParams(const FZombieWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void UZombieAttributeWidgetController::SetupZombieWidgetControllerParams(const FZombieWidgetControllerParams& Params)
{
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void UZombieAttributeWidgetController::BindCallbackToDependencies()
{
	UZombieAttributeSet* AS = Cast<UZombieAttributeSet>(AttributeSet);
	if (AS == nullptr)
	{
		return;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetHealthAttribute()).AddUObject(this, &UZombieAttributeWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxHealthAttribute()).AddUObject(this, &UZombieAttributeWidgetController::MaxHealthChanged);
}

void UZombieAttributeWidgetController::BroadcastInitialValues()
{
	UZombieAttributeSet* AS = Cast<UZombieAttributeSet>(AttributeSet);
	if (AS == nullptr)
	{
		return;
	}

	OnHealthChanged.Broadcast(AS->GetHealth());
	OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
}

void UZombieAttributeWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UZombieAttributeWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}