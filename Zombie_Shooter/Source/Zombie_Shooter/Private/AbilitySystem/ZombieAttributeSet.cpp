// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ZombieAttributeSet.h"
#include "Net/UnrealNetwork.h"

UZombieAttributeSet::UZombieAttributeSet()
{
}

void UZombieAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
}

void UZombieAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, Health, OldHealth);
}

void UZombieAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, MaxHealth, OldMaxHealth);
}

void UZombieAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UZombieAttributeSet::OnRep_CriticalChance(const FGameplayAttributeData& OldCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, CriticalChance, OldCritChance);
}
