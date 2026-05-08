// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/AISpawner.h"

void AAISpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AAISpawner::InitiateZombieSpawn, ZombieSpawnTimer, true);
}

TSubclassOf<AZombieCharacter> AAISpawner::GetRandomZombie()
{
	if (Zombies.IsEmpty() == true)
	{
		return nullptr;
	}

	int32 RandomIndex = FMath::RandRange(0, Zombies.Num() - 1);

	return Zombies[RandomIndex];
}