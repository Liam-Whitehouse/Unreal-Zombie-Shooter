// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZombieBaseDamageCalculation.h"
#include "GunDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UGunDamageCalculation : public UZombieBaseDamageCalculation
{
	GENERATED_BODY()

public:
	UGunDamageCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
