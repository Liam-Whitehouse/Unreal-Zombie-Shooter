// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ZombieAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/ZombieGameplayAbility.h"

UZombieAbilitySystemComponent::UZombieAbilitySystemComponent()
{

}

void UZombieAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UZombieAbilitySystemComponent::EffectApplied);
}

void UZombieAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& GameplayAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : GameplayAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1.0f);
		if (const UZombieGameplayAbility* ZombieAbility = Cast<UZombieGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(ZombieAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UZombieAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid() == false)
	{
		return;
	}
	
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		AbilitySpecInputPressed(AbilitySpec);
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag) == false)
		{
			return;
		}

		if (AbilitySpec.IsActive() == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Ability Spec is Active, returning."));
			return;
		}
		
		bool bDidActiveAbility = TryActivateAbility(AbilitySpec.Handle, true);
		if (bDidActiveAbility == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to Activate Abiltiy."));
			UE_LOG(LogTemp, Warning, TEXT("Abiltiy Name: [%s]"), *AbilitySpec.Ability.GetName());
			return;
		}

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UZombieAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid() == false)
	{
		return;
	}
	
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag) == false)
		{
			return;
		}

		AbilitySpecInputReleased(AbilitySpec);
	}
	
}

void UZombieAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
