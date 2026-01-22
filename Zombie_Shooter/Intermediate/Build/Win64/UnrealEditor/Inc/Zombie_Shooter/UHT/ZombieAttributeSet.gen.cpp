// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include "AttributeSet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAttributeSet() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeData();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet_NoRegister();
ZOMBIE_SHOOTER_API UScriptStruct* Z_Construct_UScriptStruct_FEffectProperties();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FEffectProperties *************************************************
struct Z_Construct_UScriptStruct_FEffectProperties_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FEffectProperties); }
	static inline consteval int16 GetStructAlignment() { return alignof(FEffectProperties); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceAvatarActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceController_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceCharacter_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceAbiltiySystemComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetAvatarActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetController_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCharacter_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetAbiltiySystemComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FEffectProperties constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceAvatarActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceAbiltiySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetAvatarActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetAbiltiySystemComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FEffectProperties constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEffectProperties>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FEffectProperties_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEffectProperties;
class UScriptStruct* FEffectProperties::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEffectProperties.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEffectProperties.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEffectProperties, (UObject*)Z_Construct_UPackage__Script_Zombie_Shooter(), TEXT("EffectProperties"));
	}
	return Z_Registration_Info_UScriptStruct_FEffectProperties.OuterSingleton;
	}

// ********** Begin ScriptStruct FEffectProperties Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceAvatarActor = { "SourceAvatarActor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, SourceAvatarActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceAvatarActor_MetaData), NewProp_SourceAvatarActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceController = { "SourceController", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, SourceController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceController_MetaData), NewProp_SourceController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceCharacter = { "SourceCharacter", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, SourceCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceCharacter_MetaData), NewProp_SourceCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceAbiltiySystemComponent = { "SourceAbiltiySystemComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, SourceAbiltiySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceAbiltiySystemComponent_MetaData), NewProp_SourceAbiltiySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetAvatarActor = { "TargetAvatarActor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, TargetAvatarActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetAvatarActor_MetaData), NewProp_TargetAvatarActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetController = { "TargetController", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, TargetController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetController_MetaData), NewProp_TargetController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, TargetCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCharacter_MetaData), NewProp_TargetCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetAbiltiySystemComponent = { "TargetAbiltiySystemComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectProperties, TargetAbiltiySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetAbiltiySystemComponent_MetaData), NewProp_TargetAbiltiySystemComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEffectProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceAvatarActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_SourceAbiltiySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetAvatarActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectProperties_Statics::NewProp_TargetAbiltiySystemComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectProperties_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FEffectProperties Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEffectProperties_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
	nullptr,
	&NewStructOps,
	"EffectProperties",
	Z_Construct_UScriptStruct_FEffectProperties_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectProperties_Statics::PropPointers),
	sizeof(FEffectProperties),
	alignof(FEffectProperties),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectProperties_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEffectProperties_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEffectProperties()
{
	if (!Z_Registration_Info_UScriptStruct_FEffectProperties.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEffectProperties.InnerSingleton, Z_Construct_UScriptStruct_FEffectProperties_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FEffectProperties.InnerSingleton);
}
// ********** End ScriptStruct FEffectProperties ***************************************************

// ********** Begin Class UZombieAttributeSet Function OnRep_CriticalChance ************************
struct Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics
{
	struct ZombieAttributeSet_eventOnRep_CriticalChance_Parms
	{
		FGameplayAttributeData OldCritChance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldCritChance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CriticalChance constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldCritChance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_CriticalChance constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_CriticalChance Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::NewProp_OldCritChance = { "OldCritChance", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAttributeSet_eventOnRep_CriticalChance_Parms, OldCritChance), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldCritChance_MetaData), NewProp_OldCritChance_MetaData) }; // 3543875268
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::NewProp_OldCritChance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::PropPointers) < 2048);
// ********** End Function OnRep_CriticalChance Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAttributeSet, nullptr, "OnRep_CriticalChance", 	Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::ZombieAttributeSet_eventOnRep_CriticalChance_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::ZombieAttributeSet_eventOnRep_CriticalChance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAttributeSet::execOnRep_CriticalChance)
{
	P_GET_STRUCT_REF(FGameplayAttributeData,Z_Param_Out_OldCritChance);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CriticalChance(Z_Param_Out_OldCritChance);
	P_NATIVE_END;
}
// ********** End Class UZombieAttributeSet Function OnRep_CriticalChance **************************

// ********** Begin Class UZombieAttributeSet Function OnRep_Health ********************************
struct Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics
{
	struct ZombieAttributeSet_eventOnRep_Health_Parms
	{
		FGameplayAttributeData OldHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldHealth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Health constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_Health constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_Health Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::NewProp_OldHealth = { "OldHealth", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAttributeSet_eventOnRep_Health_Parms, OldHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldHealth_MetaData), NewProp_OldHealth_MetaData) }; // 3543875268
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::NewProp_OldHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::PropPointers) < 2048);
// ********** End Function OnRep_Health Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAttributeSet, nullptr, "OnRep_Health", 	Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::ZombieAttributeSet_eventOnRep_Health_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::ZombieAttributeSet_eventOnRep_Health_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAttributeSet::execOnRep_Health)
{
	P_GET_STRUCT_REF(FGameplayAttributeData,Z_Param_Out_OldHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Health(Z_Param_Out_OldHealth);
	P_NATIVE_END;
}
// ********** End Class UZombieAttributeSet Function OnRep_Health **********************************

// ********** Begin Class UZombieAttributeSet Function OnRep_MaxHealth *****************************
struct Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics
{
	struct ZombieAttributeSet_eventOnRep_MaxHealth_Parms
	{
		FGameplayAttributeData OldMaxHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldMaxHealth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_MaxHealth constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldMaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_MaxHealth constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_MaxHealth Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::NewProp_OldMaxHealth = { "OldMaxHealth", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAttributeSet_eventOnRep_MaxHealth_Parms, OldMaxHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldMaxHealth_MetaData), NewProp_OldMaxHealth_MetaData) }; // 3543875268
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::NewProp_OldMaxHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::PropPointers) < 2048);
// ********** End Function OnRep_MaxHealth Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAttributeSet, nullptr, "OnRep_MaxHealth", 	Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::ZombieAttributeSet_eventOnRep_MaxHealth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::ZombieAttributeSet_eventOnRep_MaxHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAttributeSet::execOnRep_MaxHealth)
{
	P_GET_STRUCT_REF(FGameplayAttributeData,Z_Param_Out_OldMaxHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_MaxHealth(Z_Param_Out_OldMaxHealth);
	P_NATIVE_END;
}
// ********** End Class UZombieAttributeSet Function OnRep_MaxHealth *******************************

// ********** Begin Class UZombieAttributeSet Function OnRep_MovementSpeed *************************
struct Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics
{
	struct ZombieAttributeSet_eventOnRep_MovementSpeed_Parms
	{
		FGameplayAttributeData OldMovementSpeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldMovementSpeed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_MovementSpeed constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldMovementSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_MovementSpeed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_MovementSpeed Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::NewProp_OldMovementSpeed = { "OldMovementSpeed", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAttributeSet_eventOnRep_MovementSpeed_Parms, OldMovementSpeed), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldMovementSpeed_MetaData), NewProp_OldMovementSpeed_MetaData) }; // 3543875268
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::NewProp_OldMovementSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::PropPointers) < 2048);
// ********** End Function OnRep_MovementSpeed Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAttributeSet, nullptr, "OnRep_MovementSpeed", 	Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::ZombieAttributeSet_eventOnRep_MovementSpeed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::ZombieAttributeSet_eventOnRep_MovementSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAttributeSet::execOnRep_MovementSpeed)
{
	P_GET_STRUCT_REF(FGameplayAttributeData,Z_Param_Out_OldMovementSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_MovementSpeed(Z_Param_Out_OldMovementSpeed);
	P_NATIVE_END;
}
// ********** End Class UZombieAttributeSet Function OnRep_MovementSpeed ***************************

// ********** Begin Class UZombieAttributeSet ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UZombieAttributeSet;
UClass* UZombieAttributeSet::GetPrivateStaticClass()
{
	using TClass = UZombieAttributeSet;
	if (!Z_Registration_Info_UClass_UZombieAttributeSet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieAttributeSet"),
			Z_Registration_Info_UClass_UZombieAttributeSet.InnerSingleton,
			StaticRegisterNativesUZombieAttributeSet,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UZombieAttributeSet.InnerSingleton;
}
UClass* Z_Construct_UClass_UZombieAttributeSet_NoRegister()
{
	return UZombieAttributeSet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UZombieAttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "AbilitySystem/ZombieAttributeSet.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "Vital Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Vital Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementSpeed_MetaData[] = {
		{ "Category", "Vital Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CriticalChance_MetaData[] = {
		{ "Category", "Secondary Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Damage Attribute" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAttributeSet.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UZombieAttributeSet constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Health;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CriticalChance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UZombieAttributeSet constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnRep_CriticalChance"), .Pointer = &UZombieAttributeSet::execOnRep_CriticalChance },
		{ .NameUTF8 = UTF8TEXT("OnRep_Health"), .Pointer = &UZombieAttributeSet::execOnRep_Health },
		{ .NameUTF8 = UTF8TEXT("OnRep_MaxHealth"), .Pointer = &UZombieAttributeSet::execOnRep_MaxHealth },
		{ .NameUTF8 = UTF8TEXT("OnRep_MovementSpeed"), .Pointer = &UZombieAttributeSet::execOnRep_MovementSpeed },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UZombieAttributeSet_OnRep_CriticalChance, "OnRep_CriticalChance" }, // 1435459861
		{ &Z_Construct_UFunction_UZombieAttributeSet_OnRep_Health, "OnRep_Health" }, // 2589990784
		{ &Z_Construct_UFunction_UZombieAttributeSet_OnRep_MaxHealth, "OnRep_MaxHealth" }, // 1449332393
		{ &Z_Construct_UFunction_UZombieAttributeSet_OnRep_MovementSpeed, "OnRep_MovementSpeed" }, // 2135236343
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombieAttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UZombieAttributeSet_Statics

// ********** Begin Class UZombieAttributeSet Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_Health = { "Health", "OnRep_Health", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieAttributeSet, Health), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) }; // 3543875268
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_MaxHealth = { "MaxHealth", "OnRep_MaxHealth", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieAttributeSet, MaxHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) }; // 3543875268
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_MovementSpeed = { "MovementSpeed", "OnRep_MovementSpeed", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieAttributeSet, MovementSpeed), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementSpeed_MetaData), NewProp_MovementSpeed_MetaData) }; // 3543875268
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_CriticalChance = { "CriticalChance", "OnRep_CriticalChance", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieAttributeSet, CriticalChance), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CriticalChance_MetaData), NewProp_CriticalChance_MetaData) }; // 3543875268
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieAttributeSet, Damage), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) }; // 3543875268
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UZombieAttributeSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_MovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_CriticalChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieAttributeSet_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttributeSet_Statics::PropPointers) < 2048);
// ********** End Class UZombieAttributeSet Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UZombieAttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZombieAttributeSet_Statics::ClassParams = {
	&UZombieAttributeSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UZombieAttributeSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttributeSet_Statics::PropPointers),
	0,
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieAttributeSet_Statics::Class_MetaDataParams)
};
void UZombieAttributeSet::StaticRegisterNativesUZombieAttributeSet()
{
	UClass* Class = UZombieAttributeSet::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UZombieAttributeSet_Statics::Funcs));
}
UClass* Z_Construct_UClass_UZombieAttributeSet()
{
	if (!Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton, Z_Construct_UClass_UZombieAttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UZombieAttributeSet::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Health(TEXT("Health"));
	static FName Name_MaxHealth(TEXT("MaxHealth"));
	static FName Name_MovementSpeed(TEXT("MovementSpeed"));
	static FName Name_CriticalChance(TEXT("CriticalChance"));
	const bool bIsValid = true
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
		&& Name_MaxHealth == ClassReps[(int32)ENetFields_Private::MaxHealth].Property->GetFName()
		&& Name_MovementSpeed == ClassReps[(int32)ENetFields_Private::MovementSpeed].Property->GetFName()
		&& Name_CriticalChance == ClassReps[(int32)ENetFields_Private::CriticalChance].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UZombieAttributeSet"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UZombieAttributeSet);
UZombieAttributeSet::~UZombieAttributeSet() {}
// ********** End Class UZombieAttributeSet ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEffectProperties::StaticStruct, Z_Construct_UScriptStruct_FEffectProperties_Statics::NewStructOps, TEXT("EffectProperties"),&Z_Registration_Info_UScriptStruct_FEffectProperties, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEffectProperties), 1538729379U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieAttributeSet, UZombieAttributeSet::StaticClass, TEXT("UZombieAttributeSet"), &Z_Registration_Info_UClass_UZombieAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieAttributeSet), 3492717634U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_1199290000{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
