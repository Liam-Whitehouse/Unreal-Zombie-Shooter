// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/API/APIData.h"

FString UAPIData::GetAPIEndPoint(const FGameplayTag& APIEndPoint) const
{
    const FString ResourceName = Resources.FindChecked(APIEndPoint);

    FString CompleteURL = InvokeURL + "/" + StageName + "/" + ResourceName;

    return CompleteURL;
}