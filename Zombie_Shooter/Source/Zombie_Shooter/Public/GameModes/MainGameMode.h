// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/DSGameMode.h"
#include "MainGameMode.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AMainGameMode : public ADSGameMode
{
	GENERATED_BODY()

public:
	AMainGameMode();

	UFUNCTION(BlueprintCallable)
	void AddZombieCount();

	UFUNCTION(BlueprintCallable)
	void DecreaseZombieCount();

	UFUNCTION(BlueprintCallable)
	bool HasReachedMaxZombieCount() const;
	
protected:
	virtual void BeginPlay() override;

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	
	virtual void Logout(AController* Exiting) override;

	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = L"") override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Max Zombie Amount")
	int32 MaxZombieAmount = 50;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Current Zombie Amount")
	int32 CurrentZombieAmount = 0;

private:

	void TryAcceptPlayerSession(const FString& PlayerSessionID, const FString& Username, FString& OutErrorMessage);
};
