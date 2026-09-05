// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/API/GameSessions/JoinGame.h"

#include "Components/RichTextBlock.h"

void UJoinGame::SetStatusMessage(const FString& Message) const
{
	StatusMessage->SetText(FText::FromString(Message));
}
