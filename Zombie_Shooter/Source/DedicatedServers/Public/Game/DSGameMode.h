// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameLiftServer/Source/GameLiftServerSDK/Public/GameLiftServerSDK.h"
#include "DSGameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DedicatedServersLog, Log, All);

/**
 *
 */
UCLASS()
class DEDICATEDSERVERS_API ADSGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ADSGameMode();
	
protected:
	
	virtual void BeginPlay() override;
	
private:
	FProcessParameters ProcessParameters;

	void InitGameLift();

	void SetServerParameters(FServerParameters& OutParams);

	void ParseCommandLinePort(int32& OutPort);
};
