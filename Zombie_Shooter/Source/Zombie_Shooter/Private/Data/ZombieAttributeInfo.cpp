// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/ZombieAttributeInfo.h"

FAttributeInfo UZombieAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag)
{
	for (const FAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag) == true)
		{
			return Info;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Cannot find info for Attribute Tag [%s]"), *AttributeTag.ToString());
	return FAttributeInfo();
}