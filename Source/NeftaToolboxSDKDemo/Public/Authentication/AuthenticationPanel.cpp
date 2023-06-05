// Copyright 2023, Nefta, All rights reserved

#include "AuthenticationPanel.h"
#include "IntroPanel.h"
#include "GuestPanel.h"
#include "OAuthPanel.h"
#include "FullUserPanel.h"
#include "ConvertGuestIntoFullUserPanel.h"
#include "ConfirmEmailPanel.h"
#include "LoginPanel.h"
#include "LoginConfirmPanel.h"
#include <Components/WidgetSwitcher.h>

void UAuthenticationPanel::NativeConstruct()
{
    Super::NativeConstruct();
    
    IntroPanel->Init(this);
    GuestPanel->Init(this);
    OAuthPanel->Init(this);
    FullUserPanel->Init(this);
    ConvertGuestIntoFullUserPanel->Init(this);
    ConfirmEmailPanel->Init(this);
    LoginPanel->Init(this);
    LoginConfirmPanel->Init(this);
}

void UAuthenticationPanel::OpenIntro()
{
    AuthenticationSwitcher->SetActiveWidget(IntroPanel);
}

void UAuthenticationPanel::OpenOAuth()
{
    AuthenticationSwitcher->SetActiveWidget(OAuthPanel);
}

void UAuthenticationPanel::OpenGuest()
{
    AuthenticationSwitcher->SetActiveWidget(GuestPanel);
}

void UAuthenticationPanel::OpenFullUser()
{
    AuthenticationSwitcher->SetActiveWidget(FullUserPanel);
}

void UAuthenticationPanel::OpenConvertGuestIntoFullUser()
{
    AuthenticationSwitcher->SetActiveWidget(ConvertGuestIntoFullUserPanel);
}

void UAuthenticationPanel::OpenConfirmEmail(FString email)
{
    AuthenticationSwitcher->SetActiveWidget(ConfirmEmailPanel);
    ConfirmEmailPanel->SetEmail(email);
}

void UAuthenticationPanel::OpenLogin()
{
    AuthenticationSwitcher->SetActiveWidget(LoginPanel);
}

void UAuthenticationPanel::OpenLoginConfirm(FString email)
{
    AuthenticationSwitcher->SetActiveWidget(LoginConfirmPanel);
    LoginConfirmPanel->SetEmail(email);
}


