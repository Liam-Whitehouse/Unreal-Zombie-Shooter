// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Controller/ZombieController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AController();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombieController();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AZombieController_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieController ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieController;
UClass* AZombieController::GetPrivateStaticClass()
{
	using TClass = AZombieController;
	if (!Z_Registration_Info_UClass_AZombieController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieController"),
			Z_Registration_Info_UClass_AZombieController.InnerSingleton,
			StaticRegisterNativesAZombieController,
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
	return Z_Registration_Info_UClass_AZombieController.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieController_NoRegister()
{
	return AZombieController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controller/ZombieController.h" },
		{ "ModuleRelativePath", "Public/Controller/ZombieController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieController constinit property declarations ************************
// ********** End Class AZombieController constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieController_Statics
UObject* (*const Z_Construct_UClass_AZombieController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AController,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieController_Statics::ClassParams = {
	&AZombieController::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieController_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieController_Statics::Class_MetaDataParams)
};
void AZombieController::StaticRegisterNativesAZombieController()
{
}
UClass* Z_Construct_UClass_AZombieController()
{
	if (!Z_Registration_Info_UClass_AZombieController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieController.OuterSingleton, Z_Construct_UClass_AZombieController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieController.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieController);
AZombieController::~AZombieController() {}
// ********** End Class AZombieController **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieController, AZombieController::StaticClass, TEXT("AZombieController"), &Z_Registration_Info_UClass_AZombieController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieController), 2995484126U) },
	};
}; // Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h__Script_Zombie_Shooter_2691002364{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_Public_Controller_ZombieController_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
