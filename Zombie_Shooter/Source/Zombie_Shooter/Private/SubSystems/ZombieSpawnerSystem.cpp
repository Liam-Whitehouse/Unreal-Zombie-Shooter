// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/ZombieSpawnerSystem.h"
#include "Character/ZombieCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayEffectActor/BulletEffectActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Spawner/AISpawner.h"


void UZombieSpawnerSystem::LoadInZombieEnemies_Implementation(int32 amount, const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray)
{
	if (ZombieArray.Num() == 0)
	{	
		UE_LOG(LogTemp, Display, TEXT("Zombie Array is Empty in Developer Settings"));
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		int32 j = i % ZombieArray.Num();

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		FVector SpawnLocation = FVector(0.0f, 0.0f, -300.0f);
		const FTransform SpawnTransform(FRotator::ZeroRotator, SpawnLocation);

		AZombieCharacter* SpawnedActor = Cast<AZombieCharacter>(GetWorld()->SpawnActor(ZombieArray[j], &SpawnTransform, SpawnParams));
		if (SpawnedActor)
		{
			SpawnedActor->SetActorHiddenInGame(true);
			SpawnedActor->SetActorEnableCollision(false);
			SpawnedActor->SetActorTickEnabled(false);
			SpawnedActor->GetCharacterMovement()->SetComponentTickEnabled(false);

			LoadedZombies.Add(SpawnedActor);
		}
	}
}

/* 
	This wont be active for now, Ill need to figure out the drop chance so for now ill instantiate these normally on ZOmbie Death using the LootComponent.
	If there is a drop in performance, ill fix it up and add this in. 
*/
void UZombieSpawnerSystem::LoadInPickupObjects_Implementation(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor)
{
	if (EffectActor.Num() == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("PickUp Object Array is Empty in Developer Settings"));
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		int32 j = i % EffectActor.Num();

		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		AEffectActor* SpawnedActor = Cast<AEffectActor>(GetWorld()->SpawnActor(EffectActor[j], &SpawnTransform, SpawnParams));
		if (SpawnedActor)
		{
			SpawnedActor->SetActorHiddenInGame(true);
			SpawnedActor->SetActorEnableCollision(false);
			SpawnedActor->SetActorTickEnabled(false);

			LoadedPickUpItems.Add(SpawnedActor);
		}
	}
}

void UZombieSpawnerSystem::LoadInProjectileObjects_Implementation(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor)
{
	if (EffectActor.Num() == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Bullet Array is Empty in Developer Settings"));
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		int32 j = i % EffectActor.Num();

		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		ABulletEffectActor* SpawnedBullet = Cast<ABulletEffectActor>(GetWorld()->SpawnActor(EffectActor[j], &SpawnTransform, SpawnParams));
		if (SpawnedBullet)
		{
			SpawnedBullet->SetActorHiddenInGame(true);
			SpawnedBullet->SetActorEnableCollision(false);
			SpawnedBullet->SetActorTickEnabled(false);
			SpawnedBullet->GetComponentByClass<UProjectileMovementComponent>()->SetActive(false);

			LoadedBullets.Add(SpawnedBullet);
		}
	}
}