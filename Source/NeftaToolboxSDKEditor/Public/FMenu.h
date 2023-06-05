// Copyright 2023, Nefta, All rights reserved

#pragma once

class FMenu : public TSharedFromThis<FMenu>
{
public:
	virtual ~FMenu() = default;
	
	virtual void OnStartupModule();
	virtual void OnShutdownModule();

	void MakeMenuEntry(FMenuBuilder &menuBuilder);

protected:
	TSharedPtr<FUICommandList> CommandList;
	
	void ClearSession();
};
