// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/ZombieAttributeSet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAttributeSet() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAttributeSet_NoRegister();
// ********** End Cross Module References **********************************************************

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
#endif // WITH_METADATA

// ********** Begin Class UZombieAttributeSet constinit property declarations **********************
// ********** End Class UZombieAttributeSet constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombieAttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UZombieAttributeSet_Statics
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieAttributeSet_Statics::Class_MetaDataParams)
};
void UZombieAttributeSet::StaticRegisterNativesUZombieAttributeSet()
{
}
UClass* Z_Construct_UClass_UZombieAttributeSet()
{
	if (!Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton, Z_Construct_UClass_UZombieAttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZombieAttributeSet.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UZombieAttributeSet);
UZombieAttributeSet::~UZombieAttributeSet() {}
// ********** End Class UZombieAttributeSet ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieAttributeSet, UZombieAttributeSet::StaticClass, TEXT("UZombieAttributeSet"), &Z_Registration_Info_UClass_UZombieAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieAttributeSet), 918596418U) },
	};
}; // Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_3711868185{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAttributeSet_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
