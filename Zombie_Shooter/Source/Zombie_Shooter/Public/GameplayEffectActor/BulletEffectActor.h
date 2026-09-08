// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectActor/EffectActor.h"
#include "BulletEffectActor.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API ABulletEffectActor : public AEffectActor
{
	GENERATED_BODY()
	
public:
	ABulletEffectActor();

	virtual void InitializeActor(FTransform SpawnLocation) override;
	virtual void DeInitializeActor() override;
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Zombie Projectile")
	UProjectileMovementComponent* ProjectileComp;
};