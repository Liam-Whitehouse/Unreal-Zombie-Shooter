// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawner/Spawner.h"
#include "AISpawner.generated.h"

class AZombieCharacter;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AAISpawner : public ASpawner
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	TSubclassOf<AZombieCharacter> SpawnRandomZombie();

	UPROPERTY(EditDefaultsOnly, Category = "Enemies to Spawn")
	TArray<TSubclassOf<AZombieCharacter>> Zombies;

};