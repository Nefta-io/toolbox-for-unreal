// Copyright 2023, Nefta, All rights reserved

#include "LoginConfirmPanel.h"

#include "NeftaToolboxSDK.h"
#include <Components/Button.h>
#include <Components/EditableText.h>
#include "MainUi.h"

void ULoginConfirmPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;
    
	Confirm->OnClicked.AddUniqueDynamic(this, &ULoginConfirmPanel::OnConfirm);
}

void ULoginConfirmPanel::SetEmail(FString email)
{
	Email = email;
}

void ULoginConfirmPanel::OnConfirm()
{
	const FString code = ConfirmationCode->GetText().ToString();
	if (code.IsEmpty())
	{
		return;
	}
	FNeftaToolboxSDKModule::Get().Authorization->LoginWithConfirmationCode(&Email, code).BindUObject(this, &ULoginConfirmPanel::OnConfirmComplete);
}

void ULoginConfirmPanel::OnConfirmComplete(FNeftaUser& neftaUser)
{
	if (!neftaUser.IsValid())
	{
		return;
	}
	UMainUi::Instance->OpenUser();
}
