// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/Templates/SubclassOf.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "PortalHUD.generated.h"

class USignInOverlay;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API APortalHUD : public AHUD
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USignInOverlay> SignInOverlayClass;
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	TObjectPtr<USignInOverlay> SignInOverlay;
};