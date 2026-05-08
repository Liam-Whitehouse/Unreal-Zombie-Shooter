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

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void InitiateZombieSpawn();

	UFUNCTION(BlueprintPure)
	TSubclassOf<AZombieCharacter> GetRandomZombie();

	UPROPERTY(EditDefaultsOnly, Category = "Enemies to Spawn")
	TArray<TSubclassOf<AZombieCharacter>> Zombies;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Timer")
	float ZombieSpawnTimer = 3.0f;

private:
	FTimerHandle SpawnTimerHandle;

};