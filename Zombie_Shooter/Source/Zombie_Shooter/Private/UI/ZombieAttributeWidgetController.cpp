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

void UZombieAttributeWidgetController::BindCallbackToDependencies()
{

}

void UZombieAttributeWidgetController::BroadcastInitialValues()
{
	const UZombieAttributeSet* AS = Cast<UZombieAttributeSet>(AttributeSet);
	if (AS == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attribute Set is not of the type ZombieAttributeSet. Fix"));
		return;
	}

	OnHealthChanged.Broadcast(AS->GetHealth());
	OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
}