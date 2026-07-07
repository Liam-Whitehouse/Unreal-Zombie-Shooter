// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectActor/EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/BoxComponent.h"

void AEffectActor::InitializeActor_Implementation(FTransform SpawnLocation)
{
}

void AEffectActor::DeInitializeActor_Implementation()
{
}

void AEffectActor::SetEffectSpecHandle(const FGameplayEffectSpecHandle& EffectSpecHandle)
{
	GameEffectSpecHandle.Add(EffectSpecHandle);
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();

	if (EffectActorBoxComp == nullptr)
	{
		return;
	}

	EffectActorBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnBoxBeginOverlap);
}

void AEffectActor::ApplyEffectToTarget(AActor* TargetActor)
{
	if (HasAuthority() == false)
	{
		return;
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr)
	{
		return;
	}

	//I dont like this but I am a bit tired to think of a better solution currently.
	//We have this here as since we are spawning a bullet as an Effect Actor, it passes in its Spec Handle.
	//This is for when we have an a buff item on the map.
	
	for (FGameplayEffectSpecHandle& EffectSpecHandle : GameEffectSpecHandle)
	{
		if (IsValid(InstantGameplayEffectClass) == true)
		{
			EffectSpecHandle = TargetASC->MakeOutgoingSpec(InstantGameplayEffectClass, 1, TargetASC->MakeEffectContext());
		}
		
		if (EffectSpecHandle.IsValid() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Ability Effect Spec Handle is Invalid for class [%s]"), *GetName());
			return;
		}

		TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}

void AEffectActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority() == false)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Projectile overlapped %s"), *OtherActor->GetName());

	ApplyEffectToTarget(OtherActor);

	Destroy();
}