// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ZombieGameplayAbility.generated.h"

USTRUCT(Blueprintable)
struct FGameplayAbilityInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	TSubclassOf<UGameplayEffect> EffectClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability Damage")
	FScalableFloat AbilityDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevel = 3;
};

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	FGameplayEffectSpecHandle GetGameplayEffectSpecHandle();

	UFUNCTION(BlueprintCallable)
	void ApplyDamageEffectToTarget(APawn* Target);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;

	void UpgradeAbility();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayAbilityInfo> AbilityInfo;
};