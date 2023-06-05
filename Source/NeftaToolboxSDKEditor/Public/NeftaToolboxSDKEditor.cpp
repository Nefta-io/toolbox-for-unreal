// Copyright 2023, Nefta, All rights reserved

#include "NeftaToolboxSDKEditor.h"

#include "EditorStyleSet.h"
#include "LevelEditor.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogNeftaEditor);

#define LOCTEXT_NAMESPACE "FNeftaToolboxSDKEditorModule"

IMPLEMENT_MODULE(FNeftaToolboxSDKEditorModule, NeftaToolboxSDKEditor);

TSharedRef<FWorkspaceItem> FNeftaToolboxSDKEditorModule::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

void FNeftaToolboxSDKEditorModule::AddMenuExtension(const FMenuExtensionDelegate &extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList> &CommandList, EExtensionHook::Position position) const
{
	MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void FNeftaToolboxSDKEditorModule::MakePulldownMenu(FMenuBarBuilder &menuBuilder)
{
	menuBuilder.AddPullDownMenu(
		FText::FromString("Nefta Toolbox"),
		FText::FromString("Open Nefta Toolbox SDK helper"),
		FNewMenuDelegate::CreateRaw(this, &FNeftaToolboxSDKEditorModule::FillPulldownMenu),
		"Nefta Toolbox",
		FName(TEXT("Nefta Toolbox"))
	);
}

void FNeftaToolboxSDKEditorModule::FillPulldownMenu(FMenuBuilder &menuBuilder)
{
	menuBuilder.BeginSection("General", FText::FromString("General"));
	menuBuilder.AddMenuSeparator(FName("Clear saved session"));
	menuBuilder.EndSection();
}

void FNeftaToolboxSDKEditorModule::StartupModule()
{
	if (!IsRunningCommandlet())
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
		MenuExtender = MakeShareable(new FExtender);
		MenuExtender->AddMenuBarExtension("Window", EExtensionHook::After, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &FNeftaToolboxSDKEditorModule::MakePulldownMenu));
		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);

		Menu = FMenu();
		Menu.OnStartupModule();
	}
}

void FNeftaToolboxSDKEditorModule::ShutdownModule()
{
	Menu.OnShutdownModule();
}

#undef LOCTEXT_NAMESPACE
