// Copyright 2023, Nefta, All rights reserved

#include "MenuCommands.h"
#include "Framework/Commands/InputChord.h"

#define LOCTEXT_NAMESPACE "Menu"

void FMenuCommands::RegisterCommands()
{
	UI_COMMAND(ClearSessionCommand, "Clear session", "Clears saved session", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
