// Copyright 2023, Nefta, All rights reserved

#include "Authentication/OAuthPanel.h"

void UOAuthPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;
    
	Close->OnClicked.AddUniqueDynamic(this, &UOAuthPanel::OnClose);
}

void UOAuthPanel::OnClose()
{
	AuthenticationPanel->OpenIntro();
}