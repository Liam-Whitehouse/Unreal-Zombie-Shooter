// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/PlayerHUD.h"
#include "UI/ZombieUserWidget.h"

UZombieAttributeWidgetController* APlayerHUD::GetOverlayWidgetController(const FZombieWidgetControllerParams& Params)
{
	return nullptr;
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (Widget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget is invalid inside of the HUD Begin Play."));
		return;
	}

	Widget->AddToViewport();
}