// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamerManagemenet/OwnedAsset.h"
#include "AuctionPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAuctionPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UEditableText* StartPriceText;

	UPROPERTY ( meta = (BindWidget))
	UEditableText* PurchasePriceText;
    
	UPROPERTY ( meta = (BindWidget))
	class UButton* CreateAuctionButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	UFUNCTION()
	void OnCreateAuction();

	UFUNCTION()
	void OnCreateAuctionComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();

	FOwnedAsset* Asset;

	void NativeConstruct() override;

public:
	void Show(FOwnedAsset& asset);
	
};
