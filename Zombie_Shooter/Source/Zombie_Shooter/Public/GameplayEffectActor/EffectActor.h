// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "EffectActor.generated.h"

class UBoxComponent;
class UGameplayEffect;
class USphereComponent;
class UMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class ZOMBIE_SHOOTER_API AEffectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEffectActor();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void InitializeBullet(FTransform SpawnLocation);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void DeInitializeBullet();

	void SetEffectSpecHandle(FGameplayEffectSpecHandle EffectSpecHandle);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor);

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Bullet Collision")
	UBoxComponent* BulletBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Zombie Projectile")
	UProjectileMovementComponent* ProjectileComp;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	FTimerHandle BulletTimer;

	UPROPERTY(EditDefaultsOnly, Category = "Active Timer")
	float BulletActiveTimer = 8.0f;

private:
	FGameplayEffectSpecHandle GameEffectSpecHandle;
};
