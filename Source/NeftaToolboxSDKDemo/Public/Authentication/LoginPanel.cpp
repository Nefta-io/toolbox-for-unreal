// Copyright 2023, Nefta, All rights reserved

#include "LoginPanel.h"
#include <Components/Button.h>

#include "AuthenticationPanel.h"
#include "NeftaToolboxSDK.h"
#include "Components/EditableText.h"

void ULoginPanel::Init(UAuthenticationPanel* authenticationPanel)
{
    AuthenticationPanel = authenticationPanel;
    
    Confirm->OnClicked.AddUniqueDynamic(this, &ULoginPanel::OnConfirm);
    Close->OnClicked.AddUniqueDynamic(this, &ULoginPanel::OnClose);
}

void ULoginPanel::OnConfirm()
{
	const FText emailText = Email->GetText();
	if (emailText.IsEmpty())
	{
		return;
	}
	SigningEmail = emailText.ToString();
	FNeftaToolboxSDKModule::Get().Authorization->RequestLoginCode(SigningEmail).BindUObject(this, &ULoginPanel::OnConfirmComplete);
}

void ULoginPanel::OnConfirmComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		AuthenticationPanel->OpenLoginConfirm(SigningEmail);
	}
}

void ULoginPanel::OnClose()
{
	AuthenticationPanel->OpenIntro();
}