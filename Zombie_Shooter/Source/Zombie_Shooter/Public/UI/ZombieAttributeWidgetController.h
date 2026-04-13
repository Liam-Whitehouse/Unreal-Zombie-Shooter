// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/ZombieUserWidget.h"
#include "ZombieAttributeWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FZombieWidgetControllerParams
{
	GENERATED_BODY()

	FZombieWidgetControllerParams() {}
	FZombieWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	TObjectPtr<APlayerController> PC;
	TObjectPtr<APlayerState> PS;
	TObjectPtr<UAbilitySystemComponent> ASC;
	TObjectPtr<UAttributeSet> AS;
};

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieAttributeWidgetController : public UZombieUserWidget
{
	GENERATED_BODY()

public:
	void BindCallbackToDependencies() override;
	void BroadcastInitialValues() override;

};
