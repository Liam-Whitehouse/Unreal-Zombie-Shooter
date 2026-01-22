// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameModes/MainGameMode.h"

#ifdef ZOMBIE_SHOOTER_MainGameMode_generated_h
#error "MainGameMode.generated.h already included, missing '#pragma once' in MainGameMode.h"
#endif
#define ZOMBIE_SHOOTER_MainGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AMainGameMode ************************************************************
struct Z_Construct_UClass_AMainGameMode_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameMode_NoRegister();

#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainGameMode(); \
	friend struct ::Z_Construct_UClass_AMainGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_AMainGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AMainGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_AMainGameMode_NoRegister) \
	DECLARE_SERIALIZER(AMainGameMode)


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMainGameMode(AMainGameMode&&) = delete; \
	AMainGameMode(const AMainGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainGameMode) \
	NO_API virtual ~AMainGameMode();


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_12_PROLOG
#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMainGameMode;

// ********** End Class AMainGameMode **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
