// Copyright 2023, Nefta, All rights reserved


#include "CurrenciesPanel.h"
#include "CurrenciesOptionsPanel.h"
#include "CurrenciesRewardPanel.h"
#include "CurrenciesBalancePanel.h"
#include "Components/WidgetSwitcher.h"

void UCurrenciesPanel::NativeConstruct()
{
	Super::NativeConstruct();

	OptionsPanel->Init(this);
	RewardPanel->Init(this);
	BalancePanel->Init(this);
}

void UCurrenciesPanel::OpenOptions()
{
	Switcher->SetActiveWidget(OptionsPanel);
}

void UCurrenciesPanel::OpenReward()
{
	Switcher->SetActiveWidget(RewardPanel);
}

void UCurrenciesPanel::OpenBalance(FString* currencyId)
{
	Switcher->SetActiveWidget(BalancePanel);
	if (currencyId != nullptr)
	{
		BalancePanel->Show(*currencyId);
	}
}
