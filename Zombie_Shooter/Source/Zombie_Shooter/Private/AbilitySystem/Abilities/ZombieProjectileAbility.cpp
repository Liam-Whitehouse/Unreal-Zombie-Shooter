// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieProjectileAbility.h"
#include "GameplayEffectActor/EffectActor.h"

void UZombieProjectileAbility::SpawnProjectile(FTransform SpawnTransform)
{
	AEffectActor* Projectile = GetWorld()->SpawnActorDeferred<AEffectActor>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	if (Projectile == nullptr)
	{
		return;
	}

	Projectile->SetEffectSpecHandle(GetGameplayEffectSpecHandle());

	Projectile->FinishSpawning(SpawnTransform);
}