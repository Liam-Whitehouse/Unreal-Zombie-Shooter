// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Portal/PortalHUD.h"
#include "UI/Portal/SignIn/SignInOverlay.h"
#include "Blueprint/UserWidget.h"

void APortalHUD::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetOwningPlayerController();
	SignInOverlay = CreateWidget<USignInOverlay>(PlayerController, SignInOverlayClass);
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->AddToViewport();
	}
	
	FInputModeGameAndUI InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}
