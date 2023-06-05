// Copyright 2023, Nefta, All rights reserved


#include "CurrenciesBalancePanel.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include "CurrenciesPanel.h"
#include "NeftaToolboxSDK.h"
#include "Components/EditableText.h"
#include "GamerManagemenet/CurrencyBalance.h"

void UCurrenciesBalancePanel::Init(UCurrenciesPanel* currenciesPanel)
{
	CurrenciesPanel = currenciesPanel;

	ShowButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesBalancePanel::OnShow);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesBalancePanel::Close);
}

void UCurrenciesBalancePanel::OnShow()
{
	Show(CurrencyIdText->GetText().ToString());
}

void UCurrenciesBalancePanel::Show(const FString& currencyId)
{
	FNeftaToolboxSDKModule::Get().GamerManagement->GetGamerCurrencyBalance(currencyId)
	.BindUObject(this, &UCurrenciesBalancePanel::OnShowComplete);
}

void UCurrenciesBalancePanel::OnShowComplete(bool bWasSuccessful, FCurrencyBalance& balance) const
{
	if (bWasSuccessful)
	{
		BalanceText->SetText(FText::FromString(FString::Printf(TEXT("balance: %g"), balance.balance)));
	}
}

void UCurrenciesBalancePanel::Close()
{
	CurrenciesPanel->OpenOptions();
}