// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "FMenu.h"
#include "Modules/ModuleManager.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "NeftaToolboxSDK.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNeftaEditor, Log, All);

class FNeftaToolboxSDKEditorModule : public IModuleInterface
{
	ToolboxCore* Core;
	
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePulldownMenu(FMenuBarBuilder &menuBuilder);
	void FillPulldownMenu(FMenuBuilder &menuBuilder);

	FMenu Menu;
public:
	void AddMenuExtension(const FMenuExtensionDelegate &extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList> &CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before) const;
	TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FNeftaToolboxSDKEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FNeftaToolboxSDKEditorModule>("NeftaToolboxSDKEditor");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NeftaToolboxSDKEditor");
	}
};
