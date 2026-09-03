// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HTTPRequestManager.generated.h"

class UAPIData;
class FJsonObject;

/**
 * 
 */
UCLASS(Blueprintable)
class DEDICATEDSERVERS_API UHTTPRequestManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAPIData> APIData;
	
protected:
	
	bool ContainsErrors(TSharedPtr<FJsonObject> JsonObject);
	
	void DumpMetaData(TSharedPtr<FJsonObject> JsonObject) const;
};
