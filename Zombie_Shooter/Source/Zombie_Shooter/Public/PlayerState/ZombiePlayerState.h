// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Subsystems/Player/DSMatchPlayerState.h"
#include "ZombiePlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AZombiePlayerState : public ADSMatchPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AZombiePlayerState();

	virtual void OnMatchEnded(const FString& Username) override;

	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const{ return AttributeSet; }

	int32 GetZombiesKilled();

	void IncrementZombiesKilled();

protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 ZombiesKilled;
private:

};
