// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayEffectActor/EffectActor.h"
#include "LootComponent.generated.h"

USTRUCT(BlueprintType)
struct FLootItems
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot Items")
	TSubclassOf<AEffectActor> Loot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot Items")
	int32 DropChance;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ZOMBIE_SHOOTER_API ULootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULootComponent();

	UFUNCTION()
	void GenerateLoot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	TArray<FLootItems> GetLootItems();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Loot Items")
	TArray<FLootItems> Loot;

private:
	AEffectActor* GetRandomLoot();

};
