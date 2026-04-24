// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/ZombieSpawnerSystem.h"
#include "Character/ZombieCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayEffectActor/EffectActor.h"

void UZombieSpawnerSystem::LoadInZombieEnemies_Implementation(int32 amount, const TArray<TSubclassOf<AZombieCharacter>>& ZombieArray)
{
	if (ZombieArray.Num() == 0)
	{	
		UE_LOG(LogTemp, Display, TEXT("Zombie Array is Empty in Developer Settings"));
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		int32 j = i % ZombieArray.Num();

		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		AZombieCharacter* SpawnedActor = Cast<AZombieCharacter>(GetWorld()->SpawnActor(ZombieArray[j], &SpawnTransform, SpawnParams));
		if (SpawnedActor)
		{
			SpawnedActor->SetActorHiddenInGame(true);
			SpawnedActor->SetActorEnableCollision(false);
			SpawnedActor->SetActorTickEnabled(false);
			SpawnedActor->GetCharacterMovement()->SetComponentTickEnabled(false);

			LoadedZombies.Add(SpawnedActor);
		}
	}
}

void UZombieSpawnerSystem::LoadInPickupObjects_Implementation(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor)
{
	if (EffectActor.Num() == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("PickUp Object Array is Empty in Developer Settings"));
		return;
	}

	for (size_t i = 0; i < amount; i++)
	{
		int32 j = i % EffectActor.Num();

		FActorSpawnParameters SpawnParams;
		const FTransform SpawnTransform = FTransform();

		AEffectActor* SpawnedActor = Cast<AEffectActor>(GetWorld()->SpawnActor(EffectActor[j], &SpawnTransform, SpawnParams));
		if (SpawnedActor)
		{
			SpawnedActor->SetActorHiddenInGame(true);
			SpawnedActor->SetActorEnableCollision(false);
			SpawnedActor->SetActorTickEnabled(false);

			LoadedPickUpItems.Add(SpawnedActor);
		}
	}
}

void UZombieSpawnerSystem::LoadInProjectileObjects_Implementation(int32 amount, const TArray<TSubclassOf<AEffectActor>>& EffectActor)
{

}