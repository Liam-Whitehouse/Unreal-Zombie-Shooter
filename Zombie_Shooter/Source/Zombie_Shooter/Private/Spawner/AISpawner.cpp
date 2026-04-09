// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/AISpawner.h"

TSubclassOf<AZombieCharacter> AAISpawner::SpawnRandomZombie()
{
	if (Zombies.IsEmpty() == true)
	{
		return nullptr;
	}

	int32 randomIndex = FMath::RandRange(0, Zombies.Num() - 1);

	return Zombies[randomIndex];
}