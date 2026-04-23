// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ZombieSpawnerSystem.generated.h"

class AZombieCharacter;
/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieSpawnerSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<const AActor*> LoadedZombies;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void LoadInZombieEnemies(const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void LoadInPickupObjects();
};