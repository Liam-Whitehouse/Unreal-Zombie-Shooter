// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SurvivorController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"

UZombieAbilitySystemComponent* ASurvivorController::GetZombieAbilitySystemComponent()
{
	if (ZombieAbilitySystemComponent == nullptr)
	{
		ZombieAbilitySystemComponent = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}

	return ZombieAbilitySystemComponent;
}
