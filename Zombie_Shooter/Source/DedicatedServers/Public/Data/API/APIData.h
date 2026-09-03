// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "APIData.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UAPIData : public UDataAsset
{
	GENERATED_BODY()
	
public:
		
	FString GetAPIEndPoint(const FGameplayTag& APIEndPoint) const;

protected:
	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString InvokeURL;
	
	UPROPERTY(EditDefaultsOnly)
	FString StageName;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FString> Resources;
};
