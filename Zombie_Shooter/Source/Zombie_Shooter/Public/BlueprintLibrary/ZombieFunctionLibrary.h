// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZombieFunctionLibrary.generated.h"

class UZombieAttributeWidgetController;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	static UZombieAttributeWidgetController* GetWidgetController(const UObject* World);

};