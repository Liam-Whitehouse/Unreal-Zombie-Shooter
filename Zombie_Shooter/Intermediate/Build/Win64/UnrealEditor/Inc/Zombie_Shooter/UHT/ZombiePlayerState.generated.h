// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlayerState/ZombiePlayerState.h"

#ifdef ZOMBIE_SHOOTER_ZombiePlayerState_generated_h
#error "ZombiePlayerState.generated.h already included, missing '#pragma once' in ZombiePlayerState.h"
#endif
#define ZOMBIE_SHOOTER_ZombiePlayerState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombiePlayerState *******************************************************
struct Z_Construct_UClass_AZombiePlayerState_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombiePlayerState_NoRegister();

#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombiePlayerState(); \
	friend struct ::Z_Construct_UClass_AZombiePlayerState_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_AZombiePlayerState_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombiePlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_AZombiePlayerState_NoRegister) \
	DECLARE_SERIALIZER(AZombiePlayerState)


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombiePlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombiePlayerState(AZombiePlayerState&&) = delete; \
	AZombiePlayerState(const AZombiePlayerState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombiePlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombiePlayerState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombiePlayerState) \
	NO_API virtual ~AZombiePlayerState();


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_12_PROLOG
#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_15_INCLASS_NO_PURE_DECLS \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombiePlayerState;

// ********** End Class AZombiePlayerState *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
