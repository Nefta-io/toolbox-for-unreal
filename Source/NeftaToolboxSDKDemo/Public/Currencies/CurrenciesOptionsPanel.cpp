// Copyright 2023, Nefta, All rights reserved


#include "CurrenciesOptionsPanel.h"
#include <Components/Button.h>
#include "CurrenciesPanel.h"
#include "MainUi.h"

void UCurrenciesOptionsPanel::Init(UCurrenciesPanel* currenciesPanel)
{
	CurrenciesPanel = currenciesPanel;

	RewardButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesOptionsPanel::OnReward);
	BalanceButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesOptionsPanel::OnBalance);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UCurrenciesOptionsPanel::OnClose);
}

void UCurrenciesOptionsPanel::OnReward()
{
	CurrenciesPanel->OpenReward();
}

void UCurrenciesOptionsPanel::OnBalance()
{
	CurrenciesPanel->OpenBalance(nullptr);
}

void UCurrenciesOptionsPanel::OnClose()
{
	UMainUi::Instance->OpenUser();
}
