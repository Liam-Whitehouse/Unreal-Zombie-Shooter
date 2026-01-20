// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ZombieAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&)

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UZombieAbilitySystemComponent();

	void AbilityActorInfoSet();

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& GameplayAbilities);

	UFUNCTION(BlueprintCallable)
	void AbilityInputTagPressed(const FGameplayTag& InputTag);

	UFUNCTION(BlueprintCallable)
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
	
	FEffectAssetTags EffectAssetTags;

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};