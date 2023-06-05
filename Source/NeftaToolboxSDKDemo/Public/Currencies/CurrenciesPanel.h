// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrenciesPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UCurrenciesPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UWidgetSwitcher* Switcher;

	UPROPERTY ( meta = (BindWidget))
	class UCurrenciesOptionsPanel* OptionsPanel;

	UPROPERTY ( meta = (BindWidget))
	class UCurrenciesRewardPanel* RewardPanel;

	UPROPERTY ( meta = (BindWidget))
	class UCurrenciesBalancePanel* BalancePanel;

	void NativeConstruct() override;
	
public:
	void OpenOptions();

	void OpenReward();

	void OpenBalance(FString* currencyId);
};
