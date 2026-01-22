// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurvivorController.generated.h"

class UZombieAbilitySystemComponent;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API ASurvivorController : public APlayerController
{
	GENERATED_BODY()
public:
	ASurvivorController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SurvivorContext;
	
	UPROPERTY()
	UZombieAbilitySystemComponent* ZombieAbilitySystemComponent;

	UFUNCTION(BlueprintPure)
	UZombieAbilitySystemComponent* GetZombieAbilitySystemComponent();
};
