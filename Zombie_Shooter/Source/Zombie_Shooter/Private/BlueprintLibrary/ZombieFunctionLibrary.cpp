// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintLibrary/ZombieFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/PlayerHUD.h"
#include "PlayerState/ZombiePlayerState.h"
#include "UI/ZombieAttributeWidgetController.h"

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

	AZombiePlayerState* PS = PC->GetPlayerState<AZombiePlayerState>();
	if (IsValid(PS) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("PS is not valid. If I hit this, World isnt loaded or some shit"));
		return nullptr;
	}

	UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	if (ASC == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability System Component is not valid. If I hit this, World isnt loaded or some shit"));
		return nullptr;
	}

	UAttributeSet* AS = PS->GetAttributeSet();
	if (IsValid(AS) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attribute Set is not valid. If I hit this, World isnt loaded or some shit"));
		return nullptr;
	}

	const FZombieWidgetControllerParams WidgetController(PC, PS, ASC, AS);

	return HUD->GetOverlayWidgetController(WidgetController);
}