// Copyright 2023, Nefta, All rights reserved

#include "ConfirmEmailPanel.h"
#include "NeftaToolboxSDK.h"
#include <Components/Button.h>
#include <Components/EditableText.h>
#include "MainUi.h"

void UConfirmEmailPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;
    
	Confirm->OnClicked.AddUniqueDynamic(this, &UConfirmEmailPanel::OnConfirm);
}

void UConfirmEmailPanel::SetEmail(FString email)
{
	Email = email;
}

void UConfirmEmailPanel::OnConfirm()
{
	const FString code = ConfirmationCode->GetText().ToString();
	if (code.IsEmpty())
	{
		return;
	}
	FNeftaToolboxSDKModule::Get().Authorization->LoginWithConfirmationCode(&Email, code)
		.BindUObject(this, &UConfirmEmailPanel::OnConfirmComplete);
}

void UConfirmEmailPanel::OnConfirmComplete(FNeftaUser& neftaUser)
{
	if (!neftaUser.IsValid())
	{
		return;
	}
	UMainUi::Instance->OpenUser();
}
