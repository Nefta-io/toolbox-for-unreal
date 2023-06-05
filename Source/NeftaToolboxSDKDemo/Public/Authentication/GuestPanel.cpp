// Copyright 2023, Nefta, All rights reserved


#include "GuestPanel.h"
#include <Components/Button.h>
#include <Components/EditableText.h>

#include "NeftaToolboxSDK.h"
#include "MainUi.h"

void UGuestPanel::Init(UAuthenticationPanel* authenticationPanel)
{
    AuthenticationPanel = authenticationPanel;
    
    SignUpGuest->OnClicked.AddUniqueDynamic(this, &UGuestPanel::OnSignUpGuest);
    
    Close->OnClicked.AddUniqueDynamic(this, &UGuestPanel::OnClose);
}

void UGuestPanel::OnSignUpGuest()
{
    const auto username = GuestName->GetText().ToString();
    FNeftaToolboxSDKModule::Get().Authorization->SignUpGuestUser(username).BindUObject(this, &UGuestPanel::OnSignUpGuestComplete);
}

void UGuestPanel::OnSignUpGuestComplete(FNeftaUser& neftaUser)
{
    if (neftaUser.IsValid())
    {
        UMainUi::Instance->OpenUser();
    }
}

void UGuestPanel::OnClose()
{
    AuthenticationPanel->OpenIntro();
}
