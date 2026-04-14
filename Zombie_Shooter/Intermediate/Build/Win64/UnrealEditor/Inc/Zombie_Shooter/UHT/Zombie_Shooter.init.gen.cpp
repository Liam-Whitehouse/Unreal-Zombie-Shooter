// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombie_Shooter_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	ZOMBIE_SHOOTER_API UFunction* Z_Construct_UDelegateFunction_Zombie_Shooter_OnHealthChangedSignature__DelegateSignature();
	ZOMBIE_SHOOTER_API UFunction* Z_Construct_UDelegateFunction_Zombie_Shooter_OnMaxHealthChangedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Zombie_Shooter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Zombie_Shooter()
	{
		if (!Z_Registration_Info_UPackage__Script_Zombie_Shooter.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_Zombie_Shooter_OnHealthChangedSignature__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_Zombie_Shooter_OnMaxHealthChangedSignature__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/Zombie_Shooter",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x01C0002C,
			0xC569A2D7,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Zombie_Shooter.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_Zombie_Shooter.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Zombie_Shooter(Z_Construct_UPackage__Script_Zombie_Shooter, TEXT("/Script/Zombie_Shooter"), Z_Registration_Info_UPackage__Script_Zombie_Shooter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x01C0002C, 0xC569A2D7));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
