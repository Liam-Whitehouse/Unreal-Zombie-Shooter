// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SurvivorCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerState/ZombiePlayerState.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ZombieGameplayAbility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Spawner/Spawner.h"

ASurvivorCharacter::ASurvivorCharacter()
{
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	CameraArm = CreateDefaultSubobject<USpringArmComponent>("Camera Spring Arm");

	CameraArm->SetupAttachment(RootComponent);
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->AttachToComponent(CameraArm, FAttachmentTransformRules::KeepRelativeTransform);

	CameraArm->bUsePawnControlRotation = true;
	CameraArm->bEnableCameraLag = true;
	CameraArm->TargetArmLength = 300.0f;
}

void ASurvivorCharacter::BeginPlay()
{
	Super::BeginPlay();

	ASpawner* LoadedSpawner = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (IsValid(LoadedSpawner))
	{
		RespawnLocation = LoadedSpawner->GetSpawnLocation();
		return;
	}

	RespawnLocation = GetActorLocation();
}

UAbilitySystemComponent* ASurvivorCharacter::GetAbilitySystemComponent() const
{
	if (IsValid(GetPlayerState<AZombiePlayerState>()->GetAbilitySystemComponent()) == true)
	{
		return GetPlayerState<AZombiePlayerState>()->GetAbilitySystemComponent();
	}
	
	return nullptr;
}

void ASurvivorCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init Ability Actor Info for the Server
	InitAbilityActorInfo();

	AddCharacterAbilities();
}

void ASurvivorCharacter::HandleDeath()
{
	Super::HandleDeath();

	GetCharacterMovement()->DisableMovement();

	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ASurvivorCharacter::HandleRespawn, RespawnTimer, false);
}

void ASurvivorCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init Ability Actor Info the the Client
	InitAbilityActorInfo();
}

void ASurvivorCharacter::Tick(float DeltaTime)
{

}

void ASurvivorCharacter::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASurvivorCharacter::HandleRespawn()
{
	SetActorLocation(RespawnLocation);
	
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	
	GetAbilitySystemComponent()->CancelAbility(DeathAbility.GetDefaultObject());
}

void ASurvivorCharacter::MovePlayerForward(float Axis)
{
	FRotator NewRotation = FRotator::ZeroRotator;

	NewRotation.Add(0.0f, GetControlRotation().Yaw, 0.0f);

	GetActorForwardVector().Set(NewRotation.Roll, NewRotation.Pitch, NewRotation.Yaw);
	SetActorRotation(NewRotation);

	AddMovementInput(GetActorForwardVector(), Axis, false);
}

void ASurvivorCharacter::MovePlayerRight(float Axis)
{
	FRotator NewRotation = FRotator::ZeroRotator;

	NewRotation.Add(0.0f, GetControlRotation().Yaw, 0.0f);

	GetActorRightVector().Set(NewRotation.Roll, NewRotation.Pitch, NewRotation.Yaw);
	SetActorRotation(NewRotation);

	AddMovementInput(GetActorRightVector(), Axis, false);
}

void ASurvivorCharacter::InitAbilityActorInfo()
{
	AZombiePlayerState* SurvivorPlayerState = GetPlayerState<AZombiePlayerState>();
	check(SurvivorPlayerState);
	SurvivorPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SurvivorPlayerState, this);
	Cast<UZombieAbilitySystemComponent>(SurvivorPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = SurvivorPlayerState->GetAbilitySystemComponent();
	AttributeSet = SurvivorPlayerState->GetAttributeSet();

	InitializeVitalAttributes();
	InitializePrimaryAttributes();
}