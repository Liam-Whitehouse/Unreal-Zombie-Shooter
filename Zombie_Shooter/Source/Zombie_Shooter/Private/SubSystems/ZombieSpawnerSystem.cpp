// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/ZombieSpawnerSystem.h"
#include "Character/ZombieCharacter.h"

void UZombieSpawnerSystem::LoadInZombieEnemies_Implementation(const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray)
{
	for (const TSubclassOf<AZombieCharacter> Zombie : ZombieArray)
	{
		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		const AActor* SpawnedActor = GetWorld()->SpawnActor(Zombie.Get(), &SpawnTransform, SpawnParams);

		LoadedZombies.Add(SpawnedActor);
	}
}

void UZombieSpawnerSystem::LoadInPickupObjects_Implementation()
{
}