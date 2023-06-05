// Copyright 2023, Nefta, All rights reserved

#include "NeftaToolboxSDK.h"

#include "ToolboxConfiguration.h"
#include "Marketplace/MarketplaceHelper.h"

#define LOCTEXT_NAMESPACE "FNeftaToolboxSDKModule"

DEFINE_LOG_CATEGORY(LogNeftaToolbox);

IMPLEMENT_MODULE(FNeftaToolboxSDKModule, NeftaToolboxSDK);

void FNeftaToolboxSDKModule::Init()
{
	const UToolboxConfiguration* configuration = GetDefault<UToolboxConfiguration>();
	UE_LOG(LogNeftaToolbox, Log, TEXT("MarketplaceId: %s"), *FString(configuration->MarketplaceId));
	
	Core = new ToolboxCore(configuration->MarketplaceId);
	Authorization = new AuthorizationHelper(Core);
	GamerManagement = new GamerManagementHelper(Core);
	Marketplace = new MarketplaceHelper(Core);
	GamerAssets = new GamerAssetsHelper(Core);
}

FNeftaUser* FNeftaToolboxSDKModule::GetUser() const
{
	return Core->GetUser();
}


#undef LOCTEXT_NAMESPACE
