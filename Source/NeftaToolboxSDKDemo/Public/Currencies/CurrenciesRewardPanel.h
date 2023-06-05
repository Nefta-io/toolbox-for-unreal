// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrenciesRewardPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UCurrenciesRewardPanel : public UUserWidget
{
	GENERATED_BODY()

	class UCurrenciesPanel* CurrenciesPanel;

	UPROPERTY ( meta = (BindWidget))
	class UEditableText* CurrencyIdText;

	UPROPERTY ( meta = (BindWidget))
	UEditableText* AmountText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* RewardButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	UFUNCTION()
	void OnReward();

	UFUNCTION()
	void OnRewardComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();

	FString* CurrencyId;
	
public:
	void Init(UCurrenciesPanel* currenciesPanel);
};
