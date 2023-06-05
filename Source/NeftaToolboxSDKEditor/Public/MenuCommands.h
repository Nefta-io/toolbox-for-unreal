// Copyright 2023, Nefta, All rights reserved

#pragma once

class FMenuCommands : public TCommands<FMenuCommands>
{
public:
	FMenuCommands()
		: TCommands<FMenuCommands>(
		TEXT("NeftaToolboxSDK"),
		FText::FromString("Nefta Toolbox SDK Helper"),
		NAME_None,
		FAppStyle::GetAppStyleSetName()
		)
	{
	}

	virtual void RegisterCommands() override;
	
	TSharedPtr<FUICommandInfo> ClearSessionCommand;
};