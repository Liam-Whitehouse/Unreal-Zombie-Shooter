// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/DamageCalculations/GunDamageCalculation.h"

#include "ZombieGameplayTags.h"

UGunDamageCalculation::UGunDamageCalculation()
{
	
}

void UGunDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	const UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	if (SourceASC == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Source Ability System Component is Null in GunDamageCalculation"));
		return;
	}

	if (TargetASC == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Target Ability System Component is Null in GunDamageCalculation"));
		return;
	}

	AActor* SourceActor = SourceASC->GetAvatarActor();
	AActor* TargetActor = TargetASC->GetAvatarActor();

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Damage = Spec.GetSetByCallerMagnitude(FZombieGameplayTags::Get().Attribute_Damage);
	float BonusDamage = Spec.GetSetByCallerMagnitude(FZombieGameplayTags::Get().Attributes_Secondary_BonusDamage);

	if (SourceASC->HasMatchingGameplayTag(FZombieGameplayTags::Get().CriticalHit))
	{
		Damage = Damage * 2;
	}

	float FinalDamage = Damage + BonusDamage;

	const FGameplayModifierEvaluatedData EvaluatedData(UZombieAttributeSet::GetDamageAttribute(), EGameplayModOp::Additive, FinalDamage);
	OutExecutionOutput.AddOutputModifier(EvaluatedData);
}