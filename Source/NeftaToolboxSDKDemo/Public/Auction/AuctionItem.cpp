#include "AuctionItem.h"
#include "NeftaToolboxSDKDemo.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Misc/DefaultValueHelper.h"
#include "MainUi.h"

void UAuctionItem::NativeConstruct()
{
	Super::NativeConstruct();
	
	BidButton->OnClicked.AddUniqueDynamic(this, &UAuctionItem::OnBid);
	BuyButton->OnClicked.AddUniqueDynamic(this, &UAuctionItem::OnBuy);
}

void UAuctionItem::Set(FAuction& auction)
{
	Auction = &auction;

	if (auction.asset->LoadedTexture != nullptr)
	{
		OnAssetLoaded(auction.asset);
	}
	else
	{
		auction.asset->OnLoadImageCallback.AddDynamic(this, &UAuctionItem::OnAssetLoaded);
		auction.asset->LoadImage();
	}
	
	ItemNameText->SetText(FText::FromString(FString::Printf(TEXT("Item name: %s"), *auction.asset->asset_name)));
	PurchasePriceText->SetText(FText::FromString(FString::Printf(TEXT("purchase price: %s"), *auction.purchase_price)));
	SellPriceText->SetText(FText::FromString(FString::Printf(TEXT("sell price: %s"), *auction.sell_price)));
	StartPriceText->SetText(FText::FromString(FString::Printf(TEXT("start price: %s"), *auction.start_price)));
	NumberOfBidsText->SetText(FText::FromString(FString::Printf(TEXT("number of bids: %s"), *auction.number_of_bids)));
	LastBidPriceText->SetText(FText::FromString(FString::Printf(TEXT("last bid price: %s"), *auction.last_bid_price)));

	double purchasePrice = 0;
	FDefaultValueHelper::ParseDouble(auction.purchase_price, purchasePrice);
	BuyButton->SetVisibility(purchasePrice > 0 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);

	double startPrice = 0;
	FDefaultValueHelper::ParseDouble(auction.start_price, startPrice);
	BidButton->SetVisibility(startPrice > 0 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UAuctionItem::OnAssetLoaded(bool bWasSuccessful)
{
	Image->SetBrushFromTexture(Auction->asset->LoadedTexture, true);
}

void UAuctionItem::OnBid()
{
	double price = 0;
	const auto priceString = PriceInputText->GetText().ToString();
	if (FDefaultValueHelper::ParseDouble(priceString, price))
	{
		FNeftaToolboxSDKModule::Get().Marketplace->CreateAuctionBid(Auction->auction_id, price)
			.BindUObject(this, &UAuctionItem::OnBidComplete);
	}
	else
	{
		UE_LOG(LogNeftaDemo, Log, TEXT("Input correct price"));
	}
}

void UAuctionItem::OnBidComplete(bool bWasSuccessful)
{
	UE_LOG(LogNeftaDemo, Log, TEXT("Bid success: %d"), bWasSuccessful);
}

void UAuctionItem::OnBuy()
{
	FNeftaToolboxSDKModule::Get().Marketplace->CreateAuctionPurchase(Auction->auction_id)
		.BindUObject(this, &UAuctionItem::OnBuyComplete);
}

void UAuctionItem::OnBuyComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UMainUi::Instance->OpenAssets();
	}
}
