// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/GamePage.h"
#include "UI/Portal/Interface/PortalManagement.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "UI/API/GameSessions/GameSessionsManager.h"
#include "Components/RichTextBlock.h"
#include "Components/Button.h"

void UGamePage::NativeConstruct()
{
	Super::NativeConstruct();

	GameSessionsManager = NewObject<UGameSessionsManager>(this, GameSessionsManagerClass);
	GameSessionsManager->BroadcastJoinGameSessionMessage.AddDynamic(MultiplayerJoinGame, &UJoinGame::SetStatusMessage);

	MultiplayerJoinGame->JoinGameButton->OnClicked.AddDynamic(this, &UGamePage::JoinMultiplayerGame);
}

void UGamePage::JoinMultiplayerGame()
{
	MultiplayerJoinGame->JoinGameButton->SetIsEnabled(false);

	GameSessionsManager->JoinGameSession();

	GameSessionsManager->BroadcastJoinGameSessionMessage.Broadcast(TEXT("Joining Game..."), false);
}