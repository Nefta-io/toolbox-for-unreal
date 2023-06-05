// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrenciesOptionsPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UCurrenciesOptionsPanel : public UUserWidget
{
	GENERATED_BODY()

	class UCurrenciesPanel* CurrenciesPanel;
	
	UPROPERTY ( meta = (BindWidget))
	class UButton* RewardButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* BalanceButton;
	
	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	UFUNCTION()
	void OnReward();

	UFUNCTION()
	void OnBalance();

	UFUNCTION()
	void OnClose();

public:
	void Init(UCurrenciesPanel* currenciesPanel);
	
};
