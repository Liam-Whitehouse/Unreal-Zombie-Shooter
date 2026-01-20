// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieGameplayTags.h"
#include "GameplayTagsManager.h"

FZombieGameplayTags FZombieGameplayTags::GameplayTags;

void FZombieGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxHealth"), "The Max Health of the Character");
	GameplayTags.Attributes_Primary_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Health"), "The Health of the Character");
	GameplayTags.Attributes_Primary_MovementSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.MovementSpeed"), "The Movement Speed of the Character");
	GameplayTags.Attributes_Primary_CriticalChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.CriticalChance"), "The Critical Chance of the Character");

	/* InputTags */
	GameplayTags.Input_Mouse_LeftClick = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Inputs.Mouse.LeftClick"), "Sets the Input tag for the Left Mouse Button");
}