// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieGameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "ZombieGameplayTags.h"

FGameplayEffectSpecHandle UZombieGameplayAbility::GetGameplayEffectSpecHandle()
{
	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));
	if (IsValid(SourceASC) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Source Ability System Component is invalid inside %s."), *GetName());
		return FGameplayEffectSpecHandle();
	}

	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
	if (SpecHandle.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spec Handle is invalid inside %s."), *GetName());
		return FGameplayEffectSpecHandle();
	}

	FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
	const float ScaledDamage = AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);

	return SpecHandle;
}