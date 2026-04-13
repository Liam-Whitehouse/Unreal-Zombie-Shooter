// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintLibrary/ZombieFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/PlayerHUD.h"

UZombieAttributeWidgetController* UZombieFunctionLibrary::GetWidgetController(const UObject* World)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
	if (IsValid(PC) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller is not valid. If I hit this, World isnt loaded or some shit"));
		return nullptr;
	}

	APlayerHUD* HUD = Cast<APlayerHUD>(PC->GetHUD());
	if (IsValid(HUD) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD is not valid. If I hit this, World isnt loaded or some shit"));
		return nullptr;
	}

	return nullptr;
}