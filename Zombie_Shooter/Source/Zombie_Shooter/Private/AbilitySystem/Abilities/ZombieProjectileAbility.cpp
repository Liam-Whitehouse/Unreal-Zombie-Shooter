// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieProjectileAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ZombieGameplayTags.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "GameplayEffectActor/EffectActor.h"
#include "SubSystems/ZombieSpawnerSystem.h"

void UZombieProjectileAbility::SpawnProjectile(FTransform SpawnTransform)
{
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	int32 RandomIndex = FMath::RandRange(0, SpawnerSubSystem->LoadedBullets.Num() - 1);
	AEffectActor* Projectile = Cast<AEffectActor>(SpawnerSubSystem->LoadedBullets[RandomIndex]);
	SpawnerSubSystem->LoadedBullets.Remove(Projectile);

	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));
	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
	
	FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
	const float ScaledDamage = AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);
	
	Projectile->SetEffectSpecHandle(SpecHandle);
	Projectile->InitializeBullet(SpawnTransform);
}