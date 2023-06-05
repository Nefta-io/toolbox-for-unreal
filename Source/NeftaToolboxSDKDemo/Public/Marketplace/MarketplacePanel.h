// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MarketplacePanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UMarketplacePanel : public UUserWidget
{
	GENERATED_BODY()
		
	UPROPERTY ( meta = (BindWidget))
	class UButton* GetAuctions;

	UPROPERTY ( meta = (BindWidget))
	UButton* Close;

	UFUNCTION()
	void OnGetAuctions();

	UFUNCTION()
	void OnClose();

	void NativeConstruct() override;
};
