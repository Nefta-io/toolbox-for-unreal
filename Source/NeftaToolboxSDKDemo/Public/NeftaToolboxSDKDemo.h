// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "MainUi.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNeftaDemo, Log, All);

class FNeftaToolboxSDKDemoModule : public IModuleInterface
{
	void MakePulldownMenu(FMenuBarBuilder &menuBuilder);
	void FillPulldownMenu(FMenuBuilder &menuBuilder);

public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FNeftaToolboxSDKDemoModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FNeftaToolboxSDKDemoModule>("NeftaToolboxSDKDemo");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NeftaToolboxSDKDemo");
	}

	FNeftaUser* NeftaUser;

	FGamerProfile* Profile;
};
