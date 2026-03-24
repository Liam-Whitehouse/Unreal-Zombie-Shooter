// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameModes/MainGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMainGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameMode();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameMode_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AMainGameMode Function AddZombieCount ************************************
struct Z_Construct_UFunction_AMainGameMode_AddZombieCount_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddZombieCount constinit property declarations ************************
// ********** End Function AddZombieCount constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainGameMode_AddZombieCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMainGameMode, nullptr, "AddZombieCount", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGameMode_AddZombieCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainGameMode_AddZombieCount_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMainGameMode_AddZombieCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainGameMode_AddZombieCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainGameMode::execAddZombieCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddZombieCount();
	P_NATIVE_END;
}
// ********** End Class AMainGameMode Function AddZombieCount **************************************

// ********** Begin Class AMainGameMode Function DecreaseZombieCount *******************************
struct Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DecreaseZombieCount constinit property declarations *******************
// ********** End Function DecreaseZombieCount constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMainGameMode, nullptr, "DecreaseZombieCount", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainGameMode::execDecreaseZombieCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DecreaseZombieCount();
	P_NATIVE_END;
}
// ********** End Class AMainGameMode Function DecreaseZombieCount *********************************

// ********** Begin Class AMainGameMode Function HasReachedMaxZombieCount **************************
struct Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics
{
	struct MainGameMode_eventHasReachedMaxZombieCount_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasReachedMaxZombieCount constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasReachedMaxZombieCount constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasReachedMaxZombieCount Property Definitions *************************
void Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MainGameMode_eventHasReachedMaxZombieCount_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainGameMode_eventHasReachedMaxZombieCount_Parms), &Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::PropPointers) < 2048);
// ********** End Function HasReachedMaxZombieCount Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMainGameMode, nullptr, "HasReachedMaxZombieCount", 	Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::MainGameMode_eventHasReachedMaxZombieCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::MainGameMode_eventHasReachedMaxZombieCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainGameMode::execHasReachedMaxZombieCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasReachedMaxZombieCount();
	P_NATIVE_END;
}
// ********** End Class AMainGameMode Function HasReachedMaxZombieCount ****************************

// ********** Begin Class AMainGameMode ************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AMainGameMode;
UClass* AMainGameMode::GetPrivateStaticClass()
{
	using TClass = AMainGameMode;
	if (!Z_Registration_Info_UClass_AMainGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MainGameMode"),
			Z_Registration_Info_UClass_AMainGameMode.InnerSingleton,
			StaticRegisterNativesAMainGameMode,
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
	return Z_Registration_Info_UClass_AMainGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AMainGameMode_NoRegister()
{
	return AMainGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AMainGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameModes/MainGameMode.h" },
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxZombieAmount_MetaData[] = {
		{ "Category", "Max Zombie Amount" },
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentZombieAmount_MetaData[] = {
		{ "Category", "Current Zombie Amount" },
		{ "ModuleRelativePath", "Public/GameModes/MainGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AMainGameMode constinit property declarations ****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxZombieAmount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentZombieAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AMainGameMode constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddZombieCount"), .Pointer = &AMainGameMode::execAddZombieCount },
		{ .NameUTF8 = UTF8TEXT("DecreaseZombieCount"), .Pointer = &AMainGameMode::execDecreaseZombieCount },
		{ .NameUTF8 = UTF8TEXT("HasReachedMaxZombieCount"), .Pointer = &AMainGameMode::execHasReachedMaxZombieCount },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainGameMode_AddZombieCount, "AddZombieCount" }, // 313823340
		{ &Z_Construct_UFunction_AMainGameMode_DecreaseZombieCount, "DecreaseZombieCount" }, // 3988878545
		{ &Z_Construct_UFunction_AMainGameMode_HasReachedMaxZombieCount, "HasReachedMaxZombieCount" }, // 1258828077
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AMainGameMode_Statics

// ********** Begin Class AMainGameMode Property Definitions ***************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainGameMode_Statics::NewProp_MaxZombieAmount = { "MaxZombieAmount", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGameMode, MaxZombieAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxZombieAmount_MetaData), NewProp_MaxZombieAmount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainGameMode_Statics::NewProp_CurrentZombieAmount = { "CurrentZombieAmount", nullptr, (EPropertyFlags)0x0020080000010005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGameMode, CurrentZombieAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentZombieAmount_MetaData), NewProp_CurrentZombieAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGameMode_Statics::NewProp_MaxZombieAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGameMode_Statics::NewProp_CurrentZombieAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameMode_Statics::PropPointers) < 2048);
// ********** End Class AMainGameMode Property Definitions *****************************************
UObject* (*const Z_Construct_UClass_AMainGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainGameMode_Statics::ClassParams = {
	&AMainGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMainGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainGameMode_Statics::Class_MetaDataParams)
};
void AMainGameMode::StaticRegisterNativesAMainGameMode()
{
	UClass* Class = AMainGameMode::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AMainGameMode_Statics::Funcs));
}
UClass* Z_Construct_UClass_AMainGameMode()
{
	if (!Z_Registration_Info_UClass_AMainGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainGameMode.OuterSingleton, Z_Construct_UClass_AMainGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AMainGameMode);
AMainGameMode::~AMainGameMode() {}
// ********** End Class AMainGameMode **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainGameMode, AMainGameMode::StaticClass, TEXT("AMainGameMode"), &Z_Registration_Info_UClass_AMainGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainGameMode), 472024155U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h__Script_Zombie_Shooter_318713282{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_GameModes_MainGameMode_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
