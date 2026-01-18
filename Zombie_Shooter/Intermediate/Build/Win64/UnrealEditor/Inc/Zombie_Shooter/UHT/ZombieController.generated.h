// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controller/ZombieController.h"

#ifdef ZOMBIE_SHOOTER_ZombieController_generated_h
#error "ZombieController.generated.h already included, missing '#pragma once' in ZombieController.h"
#endif
#define ZOMBIE_SHOOTER_ZombieController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombieController ********************************************************
struct Z_Construct_UClass_AZombieController_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombieController_NoRegister();

#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieController(); \
	friend struct ::Z_Construct_UClass_AZombieController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_AZombieController_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombieController, AController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_AZombieController_NoRegister) \
	DECLARE_SERIALIZER(AZombieController)


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombieController(AZombieController&&) = delete; \
	AZombieController(const AZombieController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieController) \
	NO_API virtual ~AZombieController();


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_12_PROLOG
#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombieController;

// ********** End Class AZombieController **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
