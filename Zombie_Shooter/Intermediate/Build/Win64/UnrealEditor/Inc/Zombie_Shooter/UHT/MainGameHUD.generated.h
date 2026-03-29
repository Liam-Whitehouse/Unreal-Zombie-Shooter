// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HUDS/MainGameHUD.h"

#ifdef ZOMBIE_SHOOTER_MainGameHUD_generated_h
#error "MainGameHUD.generated.h already included, missing '#pragma once' in MainGameHUD.h"
#endif
#define ZOMBIE_SHOOTER_MainGameHUD_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AMainGameHUD *************************************************************
struct Z_Construct_UClass_AMainGameHUD_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameHUD_NoRegister();

#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainGameHUD(); \
	friend struct ::Z_Construct_UClass_AMainGameHUD_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_AMainGameHUD_NoRegister(); \
public: \
	DECLARE_CLASS2(AMainGameHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_AMainGameHUD_NoRegister) \
	DECLARE_SERIALIZER(AMainGameHUD)


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMainGameHUD(AMainGameHUD&&) = delete; \
	AMainGameHUD(const AMainGameHUD&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainGameHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainGameHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainGameHUD) \
	NO_API virtual ~AMainGameHUD();


#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_12_PROLOG
#define FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_15_INCLASS_NO_PURE_DECLS \
	FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMainGameHUD;

// ********** End Class AMainGameHUD ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_HUDS_MainGameHUD_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
