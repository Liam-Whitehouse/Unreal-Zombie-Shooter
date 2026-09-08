// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieGameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "ZombieGameplayTags.h"
#include <Character/BaseCharacter.h>
#include <AbilitySystem/ZombieAttributeSet.h>

FGameplayEffectSpecHandle UZombieGameplayAbility::GetGameplayEffectSpecHandle()
{
	if (GetAvatarActorFromActorInfo()->HasAuthority() == false)
	{
		return FGameplayEffectSpecHandle();
	}
	
	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));
	if (IsValid(SourceASC) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Source Ability System Component is invalid inside %s."), *GetName());
		return FGameplayEffectSpecHandle();
	}
	
	for (FGameplayAbilityInfo Info : AbilityInfo)
	{
		const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(Info.EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
		if (SpecHandle.IsValid() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spec Handle is invalid inside %s."), *GetName());
			return FGameplayEffectSpecHandle();
		}

		FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
		const float ScaledDamage = Info.AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);

		return SpecHandle;
	}
	
	//If we hit this, means our Ability Info is Empty, Not good.
	return FGameplayEffectSpecHandle();
}

void UZombieGameplayAbility::ApplyDamageEffectToTarget(APawn* Target)
{
	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));
	if (IsValid(SourceASC) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Source Ability System Component is invalid inside %s."), *GetName());
		return;
	}

	ABaseCharacter* Owner = Cast<ABaseCharacter>(GetAvatarActorFromActorInfo());
	if (IsValid(Owner) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character is Invalid and not a child of Base Character: %s."), *GetName());
		return;
	}

	UZombieAttributeSet* AS = Cast<UZombieAttributeSet>(Owner->GetAttributeSet());
	if (IsValid(AS) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attribute Set is invalid and is not of type UZombieAttributeSet on: %s."), *GetName());
		return;
	}

	for (FGameplayAbilityInfo Info : AbilityInfo)
	{
		const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(Info.EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
		if (SpecHandle.IsValid() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spec Handle is invalid inside %s."), *GetName());
			return;
		}
		
		UAbilitySystemComponent* GetTargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
		if (IsValid(GetTargetASC) == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Target Ability System Component is invalid inside of Apply Gameplay Effect To Target in [%s]."), *GetName());
			return;
		}
		
		FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
		const float ScaledDamage = Info.AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());

		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attributes_Secondary_BonusDamage, AS->GetBonusDamage());

		GetTargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void UZombieGameplayAbility::UpgradeAbility()
{
	//Need an Identifer here, unless we upgrade all our abilities, fuck it we upgrade them all
	for (FGameplayAbilityInfo Info : AbilityInfo)
	{
		if (GetAbilityLevel() == Info.MaxLevel)
		{
			return;
		}

		GetCurrentAbilitySpec()->Level = GetCurrentAbilitySpec()->Level + 1;
	}
}