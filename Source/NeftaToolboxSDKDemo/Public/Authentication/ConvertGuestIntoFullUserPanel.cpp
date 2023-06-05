// Copyright 2023, Nefta, All rights reserved

#include "ConvertGuestIntoFullUserPanel.h"

#include <Components/Button.h>

#include "AuthenticationPanel.h"
#include "NeftaToolboxSDK.h"
#include "Components/EditableText.h"
#include "MainUi.h"

void UConvertGuestIntoFullUserPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;
    
	ConfirmButton->OnClicked.AddUniqueDynamic(this, &UConvertGuestIntoFullUserPanel::OnConfirm);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UConvertGuestIntoFullUserPanel::OnClose);
}

void UConvertGuestIntoFullUserPanel::OnConfirm()
{
	const FText emailText = EmailInputText->GetText();
	if (emailText.IsEmpty())
	{
		return;
	}

	Email = emailText.ToString();
	FNeftaToolboxSDKModule::Get().Authorization->GuestFullSignup(Email)
		.BindUObject(this, &UConvertGuestIntoFullUserPanel::OnConfirmComplete);

}

void UConvertGuestIntoFullUserPanel::OnConfirmComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		AuthenticationPanel->OpenConfirmEmail(Email);
	}
}

void UConvertGuestIntoFullUserPanel::OnClose()
{
	UMainUi::Instance->OpenUser();
}
