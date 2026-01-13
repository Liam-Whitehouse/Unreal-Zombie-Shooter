// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombie_Shooter/HUDS/MainGameHUD.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMainGameHUD() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AHUD();
UPackage* Z_Construct_UPackage__Script_Zombie_Shooter();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameHUD();
ZOMBIE_SHOOTER_API UClass* Z_Construct_UClass_AMainGameHUD_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AMainGameHUD *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AMainGameHUD;
UClass* AMainGameHUD::GetPrivateStaticClass()
{
	using TClass = AMainGameHUD;
	if (!Z_Registration_Info_UClass_AMainGameHUD.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MainGameHUD"),
			Z_Registration_Info_UClass_AMainGameHUD.InnerSingleton,
			StaticRegisterNativesAMainGameHUD,
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
	return Z_Registration_Info_UClass_AMainGameHUD.InnerSingleton;
}
UClass* Z_Construct_UClass_AMainGameHUD_NoRegister()
{
	return AMainGameHUD::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AMainGameHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "HUDS/MainGameHUD.h" },
		{ "ModuleRelativePath", "HUDS/MainGameHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class AMainGameHUD constinit property declarations *****************************
// ********** End Class AMainGameHUD constinit property declarations *******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainGameHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AMainGameHUD_Statics
UObject* (*const Z_Construct_UClass_AMainGameHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_Zombie_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainGameHUD_Statics::ClassParams = {
	&AMainGameHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGameHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainGameHUD_Statics::Class_MetaDataParams)
};
void AMainGameHUD::StaticRegisterNativesAMainGameHUD()
{
}
UClass* Z_Construct_UClass_AMainGameHUD()
{
	if (!Z_Registration_Info_UClass_AMainGameHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainGameHUD.OuterSingleton, Z_Construct_UClass_AMainGameHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainGameHUD.OuterSingleton;
}
AMainGameHUD::AMainGameHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AMainGameHUD);
AMainGameHUD::~AMainGameHUD() {}
// ********** End Class AMainGameHUD ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_HUDS_MainGameHUD_h__Script_Zombie_Shooter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainGameHUD, AMainGameHUD::StaticClass, TEXT("AMainGameHUD"), &Z_Registration_Info_UClass_AMainGameHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainGameHUD), 395509610U) },
	};
}; // Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_HUDS_MainGameHUD_h__Script_Zombie_Shooter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_HUDS_MainGameHUD_h__Script_Zombie_Shooter_3749433836{
	TEXT("/Script/Zombie_Shooter"),
	Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_HUDS_MainGameHUD_h__Script_Zombie_Shooter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repos_Unreal_Zombie_Shooter_Zombie_Shooter_Source_Zombie_Shooter_HUDS_MainGameHUD_h__Script_Zombie_Shooter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
