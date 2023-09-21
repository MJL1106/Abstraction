// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbstractionNewNEw/AbstractionNewNEwGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAbstractionNewNEwGameModeBase() {}
// Cross Module References
	ABSTRACTIONNEWNEW_API UClass* Z_Construct_UClass_AAbstractionNewNEwGameModeBase_NoRegister();
	ABSTRACTIONNEWNEW_API UClass* Z_Construct_UClass_AAbstractionNewNEwGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AbstractionNewNEw();
// End Cross Module References
	void AAbstractionNewNEwGameModeBase::StaticRegisterNativesAAbstractionNewNEwGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AAbstractionNewNEwGameModeBase_NoRegister()
	{
		return AAbstractionNewNEwGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AbstractionNewNEw,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AbstractionNewNEwGameModeBase.h" },
		{ "ModuleRelativePath", "AbstractionNewNEwGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAbstractionNewNEwGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::ClassParams = {
		&AAbstractionNewNEwGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAbstractionNewNEwGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAbstractionNewNEwGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAbstractionNewNEwGameModeBase, 2259510991);
	template<> ABSTRACTIONNEWNEW_API UClass* StaticClass<AAbstractionNewNEwGameModeBase>()
	{
		return AAbstractionNewNEwGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAbstractionNewNEwGameModeBase(Z_Construct_UClass_AAbstractionNewNEwGameModeBase, &AAbstractionNewNEwGameModeBase::StaticClass, TEXT("/Script/AbstractionNewNEw"), TEXT("AAbstractionNewNEwGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAbstractionNewNEwGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
