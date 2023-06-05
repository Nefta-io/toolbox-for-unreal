// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Marketplace/Auction.h"
#include "AuctionItem.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAuctionItem : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY ( meta = (BindWidget))
	class UImage* Image;

	UPROPERTY ( meta = (BindWidget))
	class UTextBlock* ItemNameText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* BidButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* BuyButton;

	UPROPERTY ( meta = (BindWidget))
	class UEditableText* PriceInputText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* PurchasePriceText;
	
	UPROPERTY ( meta = (BindWidget))
	UTextBlock* SellPriceText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* StartPriceText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* NumberOfBidsText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* LastBidPriceText;
	
	void OnAssetLoaded(bool bWasSuccessful);
	
	UFUNCTION()
	void OnBid();

	UFUNCTION()
	void OnBidComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnBuy();

	void OnBuyComplete(bool bWasSuccessful);

	FAuction* Auction;

	void NativeConstruct() override;
	
public:
	void Set(FAuction& auction);
};