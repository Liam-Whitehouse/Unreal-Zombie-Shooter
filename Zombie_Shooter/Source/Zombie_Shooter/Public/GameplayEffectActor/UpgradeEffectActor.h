// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectActor/EffectActor.h"
#include "UpgradeEffectActor.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API AUpgradeEffectActor : public AEffectActor
{
	GENERATED_BODY()

public:
	AUpgradeEffectActor();

	virtual void InitializeActor(FTransform SpawnLocation) override;
	virtual void DeInitializeActor() override;
	
protected:

private:

};
