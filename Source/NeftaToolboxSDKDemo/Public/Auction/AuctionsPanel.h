// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Marketplace/AuctionsResponse.h"
#include "AuctionsPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAuctionsPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UScrollBox* AuctionList;
	
	UPROPERTY ( meta = (BindWidget))
	class UButton* Close;
	
	UFUNCTION()
	void OnClose();

	UFUNCTION()
	void ShowComplete(FAuctionsResponse& auctionsResponse);

	void NativeConstruct() override;

public:
	UPROPERTY (Category="Prefab", BlueprintReadWrite, meta = (BindWidgetOptional))
	TSubclassOf<class UAuctionItem> AuctionItemPrefab;
	
	UFUNCTION()
	void Show();
};
