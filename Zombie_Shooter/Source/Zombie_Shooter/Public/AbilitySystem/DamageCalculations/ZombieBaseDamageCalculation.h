// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include "ZombieBaseDamageCalculation.generated.h"

struct FSourceHealthCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);

	FSourceHealthCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, Health, Source, false);
	}
};

struct FTargetHealthCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);

	FTargetHealthCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, Health, Target, false);
	}
};

struct FSourceMaxHealthCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);

	FSourceMaxHealthCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, MaxHealth, Source, false);
	}
};

struct FTargetMaxHealthCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);

	FTargetMaxHealthCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, MaxHealth, Target, false);
	}
};

struct FSourceMovementSpeedCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(MovementSpeed);

	FSourceMovementSpeedCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, MovementSpeed, Source, false);
	}
};

struct FTargetMovementSpeedCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);

	FTargetMovementSpeedCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, MaxHealth, Target, false);
	}
};

struct FSourceCriticalChanceCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalChance);

	FSourceCriticalChanceCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, CriticalChance, Source, false);
	}
};

struct FTargetCriticalChanceCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalChance);

	FTargetCriticalChanceCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UZombieAttributeSet, CriticalChance, Target, false);
	}
};

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieBaseDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UZombieBaseDamageCalculation();

protected:
	
	static const FSourceHealthCapture& GetSourceHealth();
	static const FTargetHealthCapture& GetTargetHealth();

	static const FSourceMaxHealthCapture& GetSourceMaxHealth();
	static const FTargetMaxHealthCapture& GetTargetMaxHealth();

	static const FSourceMovementSpeedCapture& GetSourceMovementSpeed();
	static const FTargetMovementSpeedCapture& GetTargetMovementSpeed();

	static const FSourceCriticalChanceCapture& GetSourceCriticalChance();
	static const FTargetCriticalChanceCapture& GetTargetCriticalChance();
};
