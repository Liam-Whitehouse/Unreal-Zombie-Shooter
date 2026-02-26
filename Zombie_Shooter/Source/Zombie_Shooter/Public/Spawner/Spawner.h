// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class ZOMBIE_SHOOTER_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn Location")
	TObjectPtr<UCapsuleComponent> SpawnLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
