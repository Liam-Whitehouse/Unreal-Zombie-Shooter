// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * Zombie Gameplay Tags
 *
 * Singleton containing native Gameplay Tags
 */

struct FZombieGameplayTags
{
public:
	static const FZombieGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Vital_MaxHealth;
	
	FGameplayTag Attributes_Primary_Health;
	FGameplayTag Attributes_Primary_MovementSpeed;
	FGameplayTag Attributes_Primary_CriticalChance;

	/* Input Tags */
	FGameplayTag Input_Mouse_LeftClick;

	/* Meta Tags */
	FGameplayTag Attribute_Damage;
	
protected:

private:
	static FZombieGameplayTags GameplayTags;
 
};