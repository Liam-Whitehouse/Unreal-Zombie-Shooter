// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectActor/EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SubSystems/ZombieSpawnerSystem.h"

// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
	BulletBox = CreateDefaultSubobject<UBoxComponent>("Bullet Box");
	BulletBox->SetupAttachment(GetRootComponent());

	BulletBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BulletBox->SetCollisionObjectType(ECC_WorldDynamic);
	BulletBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	BulletBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("Zombie Projectile Component");
	ProjectileComp->SetIsReplicated(true);

	bReplicates = true;
}

void AEffectActor::InitializeBullet_Implementation(FTransform SpawnLocation)
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);

	SetActorTransform(SpawnLocation);
	
	ProjectileComp->SetActive(true);
	ProjectileComp->Activate(true);
	ProjectileComp->Velocity = GetActorForwardVector() * ProjectileComp->InitialSpeed;
	
	GetWorldTimerManager().SetTimer(BulletTimer, this, &AEffectActor::DeInitializeBullet, BulletActiveTimer, false);
}

void AEffectActor::DeInitializeBullet_Implementation()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	ProjectileComp->Activate(false);
	ProjectileComp->SetActive(false);

	SetActorLocation(FVector::Zero());
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	SpawnerSubSystem->LoadedBullets.Add(this);
}

void AEffectActor::SetEffectSpecHandle(FGameplayEffectSpecHandle EffectSpecHandle)
{
	GameEffectSpecHandle = EffectSpecHandle;
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();

	if (BulletBox == nullptr)
	{
		return;
	}

	BulletBox->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnBoxBeginOverlap);
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
	if (IsValid(InstantGameplayEffectClass) == true)
	{
		GameEffectSpecHandle = TargetASC->MakeOutgoingSpec(InstantGameplayEffectClass, 1, TargetASC->MakeEffectContext());
	}

	if (GameEffectSpecHandle.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability Effect Spec Handle is Invalid for class [%s]"), *GetName());
		return;
	}

	TargetASC->ApplyGameplayEffectSpecToSelf(*GameEffectSpecHandle.Data.Get());
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