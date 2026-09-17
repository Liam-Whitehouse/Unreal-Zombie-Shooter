// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "UI/Widgets/RichTextButton.h"

void UDashboardOverlay::NativeConstruct()
{
	check(SignUpButton);

	SignUpButton->SetVisibility(ESlateVisibility::Collapsed);
}