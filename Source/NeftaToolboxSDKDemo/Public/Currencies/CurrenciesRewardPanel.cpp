// Copyright 2023, Nefta, All rights reserved


#include "CurrenciesRewardPanel.h"
#include <Components/Button.h>

#include "CurrenciesPanel.h"
#include "NeftaToolboxSDK.h"
#include "Components/EditableText.h"

void UCurrenciesRewardPanel::Init(UCurrenciesPanel* currenciesPanel)
{
	CurrenciesPanel = currenciesPanel;

	RewardButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesRewardPanel::OnReward);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesRewardPanel::OnClose);
}

void UCurrenciesRewardPanel::OnReward()
{
	if (CurrencyIdText->GetText().IsEmpty())
	{
		UE_LOG(LogNeftaDemo, Log, TEXT("Missing currencyId"));
		return;
	}
	if (AmountText->GetText().IsEmpty())
	{
		UE_LOG(LogNeftaDemo, Log, TEXT("Missing amount"));
		return;
	}
	
	CurrencyId = new FString(CurrencyIdText->GetText().ToString());
	const auto amount = FCString::Atod(*AmountText->GetText().ToString());
	FNeftaToolboxSDKModule::Get().GamerAssets->CreateCurrencyRewardForUser(*CurrencyId, amount).BindUObject(this, &UCurrenciesRewardPanel::OnRewardComplete);
}

void UCurrenciesRewardPanel::OnRewardComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		CurrenciesPanel->OpenBalance(CurrencyId);
	}
}

void UCurrenciesRewardPanel::OnClose()
{
	CurrenciesPanel->OpenOptions();
}

