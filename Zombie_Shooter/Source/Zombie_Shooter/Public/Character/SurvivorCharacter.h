// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "SurvivorCharacter.generated.h"

struct FOnAttributeChangeData;
class UGameplayAbility;
class UCameraComponent;
class USpringArmComponent;
class ASpawner;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API ASurvivorCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ASurvivorCharacter();

	virtual void BeginPlay() override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void HandleDeath() override;

	virtual void OnRep_PlayerState() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInput(class UInputComponent* PlayerInputComponent);

	void HandleRespawn();
	
	void UpdateCharacterSpeed(const FOnAttributeChangeData& Data);

protected:
	UFUNCTION(BlueprintCallable)
	void MovePlayerForward(float Axis);

	UFUNCTION(BlueprintCallable)
	void MovePlayerRight(float Axis);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* PlayerCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn - Timer")
	float RespawnTimer;

	virtual void InitAbilityActorInfo() override;

private:

	FVector RespawnLocation;
	
	FTimerHandle RespawnTimerHandle;
};
