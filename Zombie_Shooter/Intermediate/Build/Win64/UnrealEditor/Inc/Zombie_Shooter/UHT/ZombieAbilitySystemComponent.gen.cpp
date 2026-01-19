// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAbilitySystemComponent() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAbilitySystemComponent();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_UZombieAbilitySystemComponent_NoRegister();
// ********** End Cross Module References **********************************************************

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
	static UObject* (*const DependentSingletons[])();
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieAbilitySystemComponent_Statics::Class_MetaDataParams)
};
void UZombieAbilitySystemComponent::StaticRegisterNativesUZombieAbilitySystemComponent()
{
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
struct Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieAbilitySystemComponent, UZombieAbilitySystemComponent::StaticClass, TEXT("UZombieAbilitySystemComponent"), &Z_Registration_Info_UClass_UZombieAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieAbilitySystemComponent), 3857664166U) },
	};
}; // Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_1270240185{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_AbilitySystem_ZombieAbilitySystemComponent_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
