// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LootComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ZOMBIE_SHOOTER_API ULootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULootComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(Blueprintpure)
	AActor* GenerateLoot();

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetLoot();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Loot Items")
	TArray<AActor*> Loot;

private:

	AActor* GetRandomLoot();

};
