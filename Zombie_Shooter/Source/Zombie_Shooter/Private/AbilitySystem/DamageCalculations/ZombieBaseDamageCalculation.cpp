// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/DamageCalculations/ZombieBaseDamageCalculation.h"

UZombieBaseDamageCalculation::UZombieBaseDamageCalculation()
{
}

const FSourceHealthCapture& UZombieBaseDamageCalculation::GetSourceHealth()
{
	static FSourceHealthCapture SourceHealth;
	return SourceHealth;
}

const FTargetHealthCapture& UZombieBaseDamageCalculation::GetTargetHealth()
{
	static FTargetHealthCapture TargetHealth;
	return TargetHealth;
}

const FSourceMaxHealthCapture& UZombieBaseDamageCalculation::GetSourceMaxHealth()
{
	static FSourceMaxHealthCapture SourceMaxHealth;
	return SourceMaxHealth;
}

const FTargetMaxHealthCapture& UZombieBaseDamageCalculation::GetTargetMaxHealth()
{
	static FTargetMaxHealthCapture TargetMaxHealth;
	return TargetMaxHealth;
}

const FSourceMovementSpeedCapture& UZombieBaseDamageCalculation::GetSourceMovementSpeed()
{
	static FSourceMovementSpeedCapture SourceMovementSpeed;
	return SourceMovementSpeed;
}

const FTargetMovementSpeedCapture& UZombieBaseDamageCalculation::GetTargetMovementSpeed()
{
	static FTargetMovementSpeedCapture TargetMovementSpeed;
	return TargetMovementSpeed;
}

const FSourceCriticalChanceCapture& UZombieBaseDamageCalculation::GetSourceCriticalChance()
{
	static FSourceCriticalChanceCapture SourceCriticalChance;
	return SourceCriticalChance;
}

const FTargetCriticalChanceCapture& UZombieBaseDamageCalculation::GetTargetCriticalChance()
{
	static FTargetCriticalChanceCapture TargetCriticalChance;
	return TargetCriticalChance;
}
