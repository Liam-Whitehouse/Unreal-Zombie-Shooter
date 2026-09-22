// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePage.generated.h"

class UJoinGame;
class URichTextButton;
class UGameSessionsManager;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UGamePage : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UJoinGame> MultiplayerJoinGame;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SoloPlayButton;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameSessionsManager> GameSessionsManagerClass;

protected:

	virtual void NativeConstruct() override;

	UFUNCTION()
	void JoinMultiplayerGame();

private:
	UPROPERTY()
	TObjectPtr<UGameSessionsManager> GameSessionsManager;

};