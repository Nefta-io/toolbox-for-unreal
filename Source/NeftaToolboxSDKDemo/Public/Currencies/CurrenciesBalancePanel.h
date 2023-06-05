// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrenciesBalancePanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UCurrenciesBalancePanel : public UUserWidget
{
	GENERATED_BODY()

	class UCurrenciesPanel* CurrenciesPanel;

	UPROPERTY ( meta = (BindWidget))
	class UTextBlock* BalanceText;
	
	UPROPERTY ( meta = (BindWidget))
	class UEditableText* CurrencyIdText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* ShowButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	UFUNCTION()
	void OnShow();

	UFUNCTION()
	void OnShowComplete(bool bWasSuccessful, FCurrencyBalance& balance) const;

	UFUNCTION()
	void Close();

public:
	void Init(UCurrenciesPanel* currenciesPanel);

	UFUNCTION()
	void Show(const FString& currencyId);
	
};
