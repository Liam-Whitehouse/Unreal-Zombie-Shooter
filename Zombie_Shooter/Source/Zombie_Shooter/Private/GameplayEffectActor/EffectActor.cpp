// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectActor/EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	///TODO, we will change this to a Gameplay Effect in Future.
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (ASCInterface == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Actor [%s] does not have an Ability System Component"), *OtherActor->GetName());
		return;
	}

	const UZombieAttributeSet* OtherActorAttributeSet = Cast<UZombieAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UZombieAttributeSet::StaticClass()));
	UZombieAttributeSet* MutableAttributeSet = const_cast<UZombieAttributeSet*>(OtherActorAttributeSet);
	MutableAttributeSet->SetHealth(OtherActorAttributeSet->GetHealth() + 50.0f);
}

void AEffectActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActor::OnOverlapEnd);
}

