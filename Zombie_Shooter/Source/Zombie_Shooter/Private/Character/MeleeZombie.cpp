// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MeleeZombie.h"


// Sets default values
AMeleeZombie::AMeleeZombie()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMeleeZombie::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMeleeZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMeleeZombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

