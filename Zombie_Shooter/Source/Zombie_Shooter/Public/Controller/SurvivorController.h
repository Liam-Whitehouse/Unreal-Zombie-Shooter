// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurvivorController.generated.h"

class UZombieAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API ASurvivorController : public APlayerController
{
	GENERATED_BODY()

private:

	UPROPERTY()
	UZombieAbilitySystemComponent* ZombieAbilitySystemComponent;

	UFUNCTION(BlueprintPure)
	UZombieAbilitySystemComponent* GetZombieAbilitySystemComponent();
};
