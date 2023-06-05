// Copyright 2023, Nefta, All rights reserved

#include "FMenu.h"

#include "EditorStyleSet.h"
#include "MenuCommands.h"
#include "NeftaToolboxSDKEditor.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "Menu"

void FMenu::OnStartupModule()
{
	CommandList = MakeShareable(new FUICommandList);
	FMenuCommands::Register();

	const auto& commands = FMenuCommands::Get();
	CommandList->MapAction(
		commands.ClearSessionCommand,
		FExecuteAction::CreateRaw(this, &FMenu::ClearSession),
		FCanExecuteAction());
	
	FNeftaToolboxSDKEditorModule::Get().AddMenuExtension(
		FMenuExtensionDelegate::CreateRaw(this, &FMenu::MakeMenuEntry),
		FName("General"),
		CommandList);
}

void FMenu::OnShutdownModule()
{
	FMenuCommands::Unregister();
}

void FMenu::MakeMenuEntry(FMenuBuilder &menuBuilder)
{
	menuBuilder.AddMenuEntry(FMenuCommands::Get().ClearSessionCommand);
}

void FMenu::ClearSession()
{
	UGameplayStatics::DeleteGameInSlot("NeftaDemoSession", 0);
	UE_LOG(LogNeftaEditor, Log, TEXT("User session cleared"));
}

#undef LOCTEXT_NAMESPACE
