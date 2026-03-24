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
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayAttributeData;

// ********** Begin ScriptStruct FEffectProperties *************************************************
struct Z_Construct_UScriptStruct_FEffectProperties_Statics;
#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_19_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FEffectProperties_Statics; \
	ZOMBIE_SHOOTER_API static class UScriptStruct* StaticStruct();


struct FEffectProperties;
// ********** End ScriptStruct FEffectProperties ***************************************************

// ********** Begin Class UZombieAttributeSet ******************************************************
#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_CriticalChance); \
	DECLARE_FUNCTION(execOnRep_MovementSpeed); \
	DECLARE_FUNCTION(execOnRep_MaxHealth); \
	DECLARE_FUNCTION(execOnRep_Health);


struct Z_Construct_UClass_UZombieAttributeSet_Statics;
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet_NoRegister();

#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUZombieAttributeSet(); \
	friend struct ::Z_Construct_UClass_UZombieAttributeSet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZOMBIE_SHOOTER_API UClass* ::Z_Construct_UClass_UZombieAttributeSet_NoRegister(); \
public: \
	DECLARE_CLASS2(UZombieAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Zombie_Shooter"), Z_Construct_UClass_UZombieAttributeSet_NoRegister) \
	DECLARE_SERIALIZER(UZombieAttributeSet) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		MaxHealth, \
		MovementSpeed, \
		CriticalChance, \
		NETFIELD_REP_END=CriticalChance	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API) \
private: \
	REPLICATED_BASE_CLASS(UZombieAttributeSet) \
public:


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UZombieAttributeSet(UZombieAttributeSet&&) = delete; \
	UZombieAttributeSet(const UZombieAttributeSet&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZombieAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZombieAttributeSet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UZombieAttributeSet) \
	NO_API virtual ~UZombieAttributeSet();


#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_47_PROLOG
#define FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_INCLASS_NO_PURE_DECLS \
	FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UZombieAttributeSet;

// ********** End Class UZombieAttributeSet ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
