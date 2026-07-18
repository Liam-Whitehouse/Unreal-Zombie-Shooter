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

	/* State Tags */
	GameplayTags.Spawn = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Gameplay.Spawn"), "Lets the Character Know they have Spawned");
	GameplayTags.Dead = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Gameplay.Dead"), "Lets Game know the this Character has Died");
	GameplayTags.Paused = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Gameplay.Paused"), "Lets Game know that this Player is Paused");
	
	/* Gameplay Ability Tags */
	GameplayTags.AttackTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Attack"), "AI Ability Attack Tag");
	
	/* Effect Tags */
	GameplayTags.CriticalHit = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Gameplay.CriticalHit"), "Notifies when an Attack is a Critical Hit");
	
	/* InputTags */
	GameplayTags.Input_Mouse_LeftClick = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Inputs.Mouse.LeftClick"), "Sets the Input tag for the Left Mouse Button");

	/* Meta Tags */
	GameplayTags.Attribute_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Damage"), "This is a Meta Attribute Tag that is the Key to our Damage");
}