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

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("Zombie Projectile Component");
	ProjectileComp->SetIsReplicated(true);

	bReplicates = true;
}

void ABulletEffectActor::InitializeActor(FTransform SpawnLocation)
{
	//We only want to spawn the bullet on the Server as its values will get replicated
	if (HasAuthority() == false)
	{
		return;
	}

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);

	SetActorTransform(SpawnLocation);

	ProjectileComp->SetActive(true);
	ProjectileComp->Activate(true);
	ProjectileComp->Velocity = GetActorForwardVector() * ProjectileComp->InitialSpeed;

	GetWorldTimerManager().SetTimer(EffectActorTimer, this, &AEffectActor::DeInitializeActor, EffectActorActiveTimer, false);
}

void ABulletEffectActor::DeInitializeActor()
{
	//Server should only be handling this
	if (HasAuthority() == false)
	{
		return;
	}

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	ProjectileComp->Velocity = FVector::ZeroVector;
	ProjectileComp->Activate(false);
	ProjectileComp->SetActive(false);

	SetActorLocation(FVector::Zero());
	SetActorRotation(FRotator::ZeroRotator);
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	SpawnerSubSystem->LoadedBullets.Add(this);
}