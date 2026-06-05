// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayEffectActor/BulletEffectActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SubSystems/ZombieSpawnerSystem.h"
#include "Components/BoxComponent.h"

ABulletEffectActor::ABulletEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
	EffectActorBoxComp = CreateDefaultSubobject<UBoxComponent>("Effect Actor Collision Box");
	EffectActorBoxComp->SetupAttachment(GetRootComponent());

	EffectActorBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	EffectActorBoxComp->SetCollisionObjectType(ECC_WorldDynamic);
	EffectActorBoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	EffectActorBoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileComp->SetUpdatedComponent(GetRootComponent());

	SetReplicateMovement(false);
	ProjectileComp->SetIsReplicated(true);

	ProjectileComp->bRotationFollowsVelocity = true;
	ProjectileComp->ProjectileGravityScale = 0.f;

	bReplicates = true;
}

void ABulletEffectActor::InitializeActor(FTransform SpawnLocation)
{
	if (!HasAuthority())
	{
		return;
	}

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	SetActorLocationAndRotation(SpawnLocation.GetLocation(), SpawnLocation.GetRotation());

	const FVector Direction = SpawnLocation.GetRotation().Vector();

	ProjectileComp->Velocity = Direction * ProjectileComp->InitialSpeed;

	ProjectileComp->Activate(true);

	ForceNetUpdate();

	GetWorldTimerManager().SetTimer(EffectActorTimer, this, &AEffectActor::DeInitializeActor, EffectActorActiveTimer, false);
}

void ABulletEffectActor::DeInitializeActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	ProjectileComp->StopMovementImmediately();
	ProjectileComp->Deactivate();

	SetActorLocation(FVector::Zero());
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	SpawnerSubSystem->LoadedBullets.Add(this);
}