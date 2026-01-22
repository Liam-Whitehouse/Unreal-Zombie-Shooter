// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ZombieGameplayAbility.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	FGameplayEffectSpecHandle GetGameplayEffectSpecHandle();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	TSubclassOf<UGameplayEffect> EffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability Damage")
	FScalableFloat AbilityDamage;

protected:

};
