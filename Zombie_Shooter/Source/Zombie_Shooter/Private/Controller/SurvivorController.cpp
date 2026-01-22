// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SurvivorController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


ASurvivorController::ASurvivorController()
{
	bReplicates = true;
}

void ASurvivorController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController() == false)
	{
		return;
	}
	
	check(SurvivorContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(SurvivorContext, 0);
}

void ASurvivorController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
}

UZombieAbilitySystemComponent* ASurvivorController::GetZombieAbilitySystemComponent()
{
	if (ZombieAbilitySystemComponent == nullptr)
	{
		ZombieAbilitySystemComponent = Cast<UZombieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}

	return ZombieAbilitySystemComponent;
}
