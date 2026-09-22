// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/API/GameSessions/JoinGame.h"

#include "Components/RichTextBlock.h"
#include "Components/Button.h"

void UJoinGame::SetStatusMessage(const FString& Message, bool bShouldResetWidgets)
{
	StatusMessage->SetText(FText::FromString(Message));

	if (bShouldResetWidgets)
	{
		JoinGameButton->SetIsEnabled(true);
	}
}
