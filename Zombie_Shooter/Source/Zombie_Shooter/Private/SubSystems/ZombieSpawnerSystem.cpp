// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/ZombieSpawnerSystem.h"
#include "Character/ZombieCharacter.h"

void UZombieSpawnerSystem::LoadInZombieEnemies_Implementation(const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray)
{
	for (const TSubclassOf Zombie : ZombieArray)
	{
		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		AActor* SpawnedActor = GetWorld()->SpawnActor(Zombie, &SpawnTransform, SpawnParams);
		if (SpawnedActor)
		{
			SpawnedActor->SetActorHiddenInGame(true);
			SpawnedActor->SetActorEnableCollision(false);
			SpawnedActor->SetActorTickEnabled(false);
		
			LoadedZombies.Add(SpawnedActor);	
		}
	}
}

void UZombieSpawnerSystem::LoadInPickupObjects_Implementation()
{
}