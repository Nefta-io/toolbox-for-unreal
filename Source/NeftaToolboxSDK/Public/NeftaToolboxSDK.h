// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "ToolboxCore.h"
#include "Authorization/AuthorizationHelper.h"
#include "GamerAssets/GamerAssetsHelper.h"
#include "GamerManagemenet/GamerManagementHelper.h"
#include "Marketplace/MarketplaceHelper.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNeftaToolbox, Log, Verbose);

class NEFTATOOLBOXSDK_API FNeftaToolboxSDKModule : public IModuleInterface
{
	ToolboxCore* Core;
	
public:
	static inline FNeftaToolboxSDKModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FNeftaToolboxSDKModule>("NeftaToolboxSDK");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NeftaToolboxSDK");
	}

	void Init();
    
	AuthorizationHelper* Authorization;
	GamerManagementHelper* GamerManagement;
	MarketplaceHelper* Marketplace;
	GamerAssetsHelper* GamerAssets;

	FNeftaUser* GetUser() const;
};
