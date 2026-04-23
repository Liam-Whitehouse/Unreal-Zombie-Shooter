// Fill out your copyright notice in the Description page of Project Settings.


#include "DeveloperSettings/ZombieDeveloperSettings.h"

UZombieDeveloperSettings::UZombieDeveloperSettings()
{
	
}

const UZombieDeveloperSettings* UZombieDeveloperSettings::GetZombieDeveloperSettings()
{
	return GetDefault<UZombieDeveloperSettings>();
}
