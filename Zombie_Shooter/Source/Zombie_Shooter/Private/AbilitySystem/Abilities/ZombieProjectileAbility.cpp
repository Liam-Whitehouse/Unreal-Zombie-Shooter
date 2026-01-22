// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieProjectileAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ZombieGameplayTags.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "GameplayEffectActor/EffectActor.h"

void UZombieProjectileAbility::SpawnProjectile(FTransform SpawnTransform)
{
	if (GetAvatarActorFromActorInfo()->HasAuthority() == false)
	{
		return;
	}
	
	AEffectActor* Projectile = GetWorld()->SpawnActorDeferred<AEffectActor>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	if (Projectile == nullptr)
	{
		return;
	}

	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));
	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
	
	FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
	const float ScaledDamage = AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);
	
	Projectile->SetEffectSpecHandle(SpecHandle);
	Projectile->FinishSpawning(SpawnTransform);
}