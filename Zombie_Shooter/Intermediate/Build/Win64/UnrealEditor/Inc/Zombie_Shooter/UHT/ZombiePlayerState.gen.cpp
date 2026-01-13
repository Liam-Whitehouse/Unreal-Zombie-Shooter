// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombie_Shooter/PlayerState/ZombiePlayerState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombiePlayerState() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombiePlayerState();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombiePlayerState_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombiePlayerState *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombiePlayerState;
UClass* AZombiePlayerState::GetPrivateStaticClass()
{
	using TClass = AZombiePlayerState;
	if (!Z_Registration_Info_UClass_AZombiePlayerState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombiePlayerState"),
			Z_Registration_Info_UClass_AZombiePlayerState.InnerSingleton,
			StaticRegisterNativesAZombiePlayerState,
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
	return Z_Registration_Info_UClass_AZombiePlayerState.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombiePlayerState_NoRegister()
{
	return AZombiePlayerState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombiePlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PlayerState/ZombiePlayerState.h" },
		{ "ModuleRelativePath", "PlayerState/ZombiePlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombiePlayerState constinit property declarations ***********************
// ********** End Class AZombiePlayerState constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombiePlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombiePlayerState_Statics
UObject* (*const Z_Construct_UClass_AZombiePlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombiePlayerState_Statics::ClassParams = {
	&AZombiePlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombiePlayerState_Statics::Class_MetaDataParams)
};
void AZombiePlayerState::StaticRegisterNativesAZombiePlayerState()
{
}
UClass* Z_Construct_UClass_AZombiePlayerState()
{
	if (!Z_Registration_Info_UClass_AZombiePlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombiePlayerState.OuterSingleton, Z_Construct_UClass_AZombiePlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombiePlayerState.OuterSingleton;
}
AZombiePlayerState::AZombiePlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombiePlayerState);
AZombiePlayerState::~AZombiePlayerState() {}
// ********** End Class AZombiePlayerState *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombiePlayerState, AZombiePlayerState::StaticClass, TEXT("AZombiePlayerState"), &Z_Registration_Info_UClass_AZombiePlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombiePlayerState), 1431194854U) },
	};
}; // Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h__Script_Zombie_Shooter_2974131760{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_PlayerState_ZombiePlayerState_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
