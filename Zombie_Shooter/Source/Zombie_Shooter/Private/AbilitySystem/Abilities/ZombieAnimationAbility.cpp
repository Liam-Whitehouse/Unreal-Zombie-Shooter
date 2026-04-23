// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ZombieAnimationAbility.h"


void UZombieAnimationAbility::EndAnimationAbility()
{
    EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true, false);
}