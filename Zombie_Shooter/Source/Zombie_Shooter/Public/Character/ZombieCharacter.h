// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ZombieCharacter.generated.h"

class ULootComponent;
class UBehaviorTree;
class AAIZombieController;
class UWidgetComponent;
class UZombieUserWidget;

UENUM(BlueprintType)
enum class EZombieClassType : uint8
{
	Melee UMETA(DisplayName = "Melee Zombie"),
	Ranged UMETA(DisplayName = "Ranged Zombie"),
	Bruiser UMETA(DisplayName = "Bruiser Zombie")
};

UCLASS()
class ZOMBIE_SHOOTER_API AZombieCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieCharacter();

	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetCurrentTarget(APawn* NewTarget);

	UFUNCTION(BlueprintPure)
	APawn* GetCurrentTarget();

	virtual void InitAbilityActorInfo() override;

	virtual void InitializeDefaultAttributes() override;

	virtual void HandleDeath() override;

	UFUNCTION(BlueprintCallable)
	float GetAggressionRange() const;

	EZombieClassType GetClassType();

protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Aggression Range")
	float AggressionRange = 1000.f;

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAIZombieController> ZombieAIController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	TObjectPtr<ULootComponent> LootComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Component")
	TObjectPtr<UWidgetComponent> HealthBarWidget;

	UPROPERTY()
	TObjectPtr<APawn> Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	EZombieClassType ClassType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	TObjectPtr<UAnimMontage> DeathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	TObjectPtr<UAnimMontage> SpawnAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	TArray<TObjectPtr<UAnimMontage>> AttackAnims;

private:
	void HandleDestruction();
};
