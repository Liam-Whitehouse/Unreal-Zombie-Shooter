// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/Spawner.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	SpawnLocation = CreateDefaultSubobject<UCapsuleComponent>("Spawn Location");

	BaseMesh->SetupAttachment(RootComponent);
	SpawnLocation->SetupAttachment(BaseMesh);

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

