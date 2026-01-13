// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/ZombieAttributeSet.h"

#ifdef ZOMBIE_SHOOTER_ZombieAttributeSet_generated_h
#error "ZombieAttributeSet.generated.h already included, missing '#pragma once' in ZombieAttributeSet.h"
#endif
#define ZOMBIE_SHOOTER_ZombieAttributeSet_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UZombieAttributeSet ******************************************************
struct Z_Construct_UClass_UZombieAttributeSet_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet_NoRegister();

#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUZombieAttributeSet(); \
	friend struct ::Z_Construct_UClass_UZombieAttributeSet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_UZombieAttributeSet_NoRegister(); \
public: \
	DECLARE_CLASS2(UZombieAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_UZombieAttributeSet_NoRegister) \
	DECLARE_SERIALIZER(UZombieAttributeSet)


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZombieAttributeSet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UZombieAttributeSet(UZombieAttributeSet&&) = delete; \
	UZombieAttributeSet(const UZombieAttributeSet&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZombieAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZombieAttributeSet); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZombieAttributeSet) \
	NO_API virtual ~UZombieAttributeSet();


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_12_PROLOG
#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_15_INCLASS_NO_PURE_DECLS \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UZombieAttributeSet;

// ********** End Class UZombieAttributeSet ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_AbilitySystem_ZombieAttributeSet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
