// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/ZombieAbilitySystemComponent.h"

#ifdef ZOMBIE_SHOOTER_ZombieAbilitySystemComponent_generated_h
#error "ZombieAbilitySystemComponent.generated.h already included, missing '#pragma once' in ZombieAbilitySystemComponent.h"
#endif
#define ZOMBIE_SHOOTER_ZombieAbilitySystemComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;

// ********** Begin Class UZombieAbilitySystemComponent ********************************************
#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAbilityInputTagReleased); \
	DECLARE_FUNCTION(execAbilityInputTagPressed);


struct Z_Construct_UClass_UZombieAbilitySystemComponent_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister();

#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUZombieAbilitySystemComponent(); \
	friend struct ::Z_Construct_UClass_UZombieAbilitySystemComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UZombieAbilitySystemComponent, UAbilitySystemComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister) \
	DECLARE_SERIALIZER(UZombieAbilitySystemComponent)


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UZombieAbilitySystemComponent(UZombieAbilitySystemComponent&&) = delete; \
	UZombieAbilitySystemComponent(const UZombieAbilitySystemComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZombieAbilitySystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZombieAbilitySystemComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UZombieAbilitySystemComponent) \
	NO_API virtual ~UZombieAbilitySystemComponent();


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_14_PROLOG
#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UZombieAbilitySystemComponent;

// ********** End Class UZombieAbilitySystemComponent **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
