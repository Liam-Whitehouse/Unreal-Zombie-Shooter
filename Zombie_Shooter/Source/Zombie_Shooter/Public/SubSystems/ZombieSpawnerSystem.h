// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ZombieSpawnerSystem.generated.h"

class AZombieCharacter;
class AEffectActor;

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

	UPROPERTY(BlueprintReadWrite)
	TArray<const AActor*> LoadedPickUpItems;


	UFUNCTION(Server, Reliable, BlueprintCallable)
	void LoadInZombieEnemies(int32 amount, const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void LoadInPickupObjects(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void LoadInProjectileObjects(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor);
};