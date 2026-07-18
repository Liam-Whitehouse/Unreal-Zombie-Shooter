// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/PlayerHUD.h"
#include "UI/ZombieUserWidget.h"
#include "UI/ZombieAttributeWidgetController.h"

UZombieAttributeWidgetController* APlayerHUD::GetOverlayWidgetController(const FZombieWidgetControllerParams& Params)
{
	if (OverlayWidgetController)
	{
		return OverlayWidgetController;
	}

	OverlayWidgetController = NewObject<UZombieAttributeWidgetController>(this, OverlayWidgetControllerClass);
	OverlayWidgetController->SetupWidgetControllerParams(Params);
	OverlayWidgetController->BindCallbackToDependencies();

	return OverlayWidgetController;
}

void APlayerHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class is not set"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class is not set"));


	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (Widget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget is invalid inside of the HUD Begin Play."));
		return;
	}

	OverlayWidget = Cast<UZombieUserWidget>(Widget);
	if (OverlayWidget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ZombieWidget is not valid, most likely due to Widget's parent class not being a Zombie Widget"));
		return;
	}

	const FZombieWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UZombieAttributeWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();

	Widget->AddToViewport();
}