// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ZombieAttributeWidgetController.h"

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

}