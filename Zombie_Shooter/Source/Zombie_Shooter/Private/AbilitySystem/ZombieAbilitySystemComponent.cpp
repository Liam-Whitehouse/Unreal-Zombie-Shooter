// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ZombieAbilitySystemComponent.h"

UZombieAbilitySystemComponent::UZombieAbilitySystemComponent()
{

}

void UZombieAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UZombieAbilitySystemComponent::EffectApplied);
}

void UZombieAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}