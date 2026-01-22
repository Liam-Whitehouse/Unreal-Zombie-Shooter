// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ZombieGameplayAbility.h"
#include "ZombieProjectileAbility.generated.h"

class AEffectActor;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieProjectileAbility : public UZombieGameplayAbility
{
	GENERATED_BODY()

public:



protected:

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(FTransform SpawnTransform);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AEffectActor> ProjectileClass;
private:


};
