// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAbilitySystemComponent() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAbilitySystemComponent();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UZombieAbilitySystemComponent Function AbilityInputTagPressed ************
struct Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics
{
	struct ZombieAbilitySystemComponent_eventAbilityInputTagPressed_Parms
	{
		FGameplayTag InputTag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AbilityInputTagPressed constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InputTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AbilityInputTagPressed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AbilityInputTagPressed Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::NewProp_InputTag = { "InputTag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAbilitySystemComponent_eventAbilityInputTagPressed_Parms, InputTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputTag_MetaData), NewProp_InputTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::NewProp_InputTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::PropPointers) < 2048);
// ********** End Function AbilityInputTagPressed Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAbilitySystemComponent, nullptr, "AbilityInputTagPressed", 	Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::ZombieAbilitySystemComponent_eventAbilityInputTagPressed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::ZombieAbilitySystemComponent_eventAbilityInputTagPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAbilitySystemComponent::execAbilityInputTagPressed)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_InputTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AbilityInputTagPressed(Z_Param_Out_InputTag);
	P_NATIVE_END;
}
// ********** End Class UZombieAbilitySystemComponent Function AbilityInputTagPressed **************

// ********** Begin Class UZombieAbilitySystemComponent Function AbilityInputTagReleased ***********
struct Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics
{
	struct ZombieAbilitySystemComponent_eventAbilityInputTagReleased_Parms
	{
		FGameplayTag InputTag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AbilityInputTagReleased constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InputTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AbilityInputTagReleased constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AbilityInputTagReleased Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::NewProp_InputTag = { "InputTag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieAbilitySystemComponent_eventAbilityInputTagReleased_Parms, InputTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputTag_MetaData), NewProp_InputTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::NewProp_InputTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::PropPointers) < 2048);
// ********** End Function AbilityInputTagReleased Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieAbilitySystemComponent, nullptr, "AbilityInputTagReleased", 	Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::ZombieAbilitySystemComponent_eventAbilityInputTagReleased_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::ZombieAbilitySystemComponent_eventAbilityInputTagReleased_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieAbilitySystemComponent::execAbilityInputTagReleased)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_InputTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AbilityInputTagReleased(Z_Param_Out_InputTag);
	P_NATIVE_END;
}
// ********** End Class UZombieAbilitySystemComponent Function AbilityInputTagReleased *************

// ********** Begin Class UZombieAbilitySystemComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UZombieAbilitySystemComponent;
UClass* UZombieAbilitySystemComponent::GetPrivateStaticClass()
{
	using TClass = UZombieAbilitySystemComponent;
	if (!Z_Registration_Info_UClass_UZombieAbilitySystemComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieAbilitySystemComponent"),
			Z_Registration_Info_UClass_UZombieAbilitySystemComponent.InnerSingleton,
			StaticRegisterNativesUZombieAbilitySystemComponent,
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
	return Z_Registration_Info_UClass_UZombieAbilitySystemComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister()
{
	return UZombieAbilitySystemComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UZombieAbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "AbilitySystem/ZombieAbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/ZombieAbilitySystemComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UZombieAbilitySystemComponent constinit property declarations ************
// ********** End Class UZombieAbilitySystemComponent constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AbilityInputTagPressed"), .Pointer = &UZombieAbilitySystemComponent::execAbilityInputTagPressed },
		{ .NameUTF8 = UTF8TEXT("AbilityInputTagReleased"), .Pointer = &UZombieAbilitySystemComponent::execAbilityInputTagReleased },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagPressed, "AbilityInputTagPressed" }, // 2480737549
		{ &Z_Construct_UFunction_UZombieAbilitySystemComponent_AbilityInputTagReleased, "AbilityInputTagReleased" }, // 1148642592
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombieAbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UZombieAbilitySystemComponent_Statics
UObject* (*const Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::ClassParams = {
	&UZombieAbilitySystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::Class_MetaDataParams)
};
void UZombieAbilitySystemComponent::StaticRegisterNativesUZombieAbilitySystemComponent()
{
	UClass* Class = UZombieAbilitySystemComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UZombieAbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UZombieAbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZombieAbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZombieAbilitySystemComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UZombieAbilitySystemComponent);
UZombieAbilitySystemComponent::~UZombieAbilitySystemComponent() {}
// ********** End Class UZombieAbilitySystemComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieAbilitySystemComponent, UZombieAbilitySystemComponent::StaticClass, TEXT("UZombieAbilitySystemComponent"), &Z_Registration_Info_UClass_UZombieAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieAbilitySystemComponent), 3261961737U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_1552603663{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Work_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
