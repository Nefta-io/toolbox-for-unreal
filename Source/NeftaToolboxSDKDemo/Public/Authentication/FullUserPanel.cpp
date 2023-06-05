// Copyright 2023, Nefta, All rights reserved

#include "FullUserPanel.h"

#include <Components/Button.h>

#include "AuthenticationPanel.h"
#include "NeftaToolboxSDK.h"
#include "Components/EditableText.h"

void UFullUserPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;

	SignUp->OnClicked.AddUniqueDynamic(this, &UFullUserPanel::OnSignUp);
	Close->OnClicked.AddUniqueDynamic(this, &UFullUserPanel::OnClose);
}

void UFullUserPanel::OnSignUp()
{
	const FText emailText = Email->GetText();
	if (emailText.IsEmpty())
	{
		return;
	}
	UserEmail = emailText.ToString();
	const FString username = Username->GetText().ToString();
	FNeftaToolboxSDKModule::Get().Authorization->SignUpGamer(&UserEmail, username).BindUObject(this, &UFullUserPanel::OnSignUpComplete);
}

void UFullUserPanel::OnSignUpComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		AuthenticationPanel->OpenConfirmEmail(UserEmail);
	}
}

void UFullUserPanel::OnClose()
{
	AuthenticationPanel->OpenIntro();
}

