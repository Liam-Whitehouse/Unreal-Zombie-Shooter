// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieProjectileAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ZombieGameplayTags.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "GameplayEffectActor/BulletEffectActor.h"
#include "SubSystems/ZombieSpawnerSystem.h"

void UZombieProjectileAbility::SpawnProjectile(FTransform SpawnTransform)
{
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	if (SpawnerSubSystem->LoadedBullets.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Bullets Loaded in Spawner Subsystem"));
		return;
	}
	
	int32 RandomIndex = FMath::RandRange(0, SpawnerSubSystem->LoadedBullets.Num() - 1);
	ABulletEffectActor* Projectile = Cast<ABulletEffectActor>(SpawnerSubSystem->LoadedBullets[RandomIndex]);
	SpawnerSubSystem->LoadedBullets.Remove(Projectile);

	const UZombieAbilitySystemComponent* SourceASC = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo()));

	for (FGameplayAbilityInfo Info : AbilityInfo)
	{
		const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(Info.EffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());
		
		FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
		const float ScaledDamage = Info.AbilityDamage.GetValueAtLevel(SpecHandle.Data.Get()->GetLevel());
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);
		Projectile->SetEffectSpecHandle(SpecHandle);
	}
	
	Projectile->InitializeActor(SpawnTransform);
}