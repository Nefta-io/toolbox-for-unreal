#pragma once
#include "ToolboxCore.h"
#include "Auction.h"
#include "AuctionsResponse.h"

class NEFTATOOLBOXSDK_API MarketplaceHelper
{
	ToolboxCore* Core;

	DECLARE_DELEGATE_OneParam(OnCreateAuctionDelegate, bool);
	OnCreateAuctionDelegate OnCreateAuctionCallback;
	void OnCreateAuction(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_OneParam(OnGetProjectAuctionsDelegate, FAuctionsResponse&);
	OnGetProjectAuctionsDelegate OnGetProjectAuctionsCallback;
	void OnGetProjectAuctions(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_OneParam(OnCreateAuctionBidDelegate, bool);
	OnCreateAuctionBidDelegate OnCreateAuctionBidCallback;
	void OnCreateAuctionBid(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	DECLARE_DELEGATE_OneParam(OnCreateAuctionPurchaseDelegate, bool);
	OnCreateAuctionPurchaseDelegate OnCreateAuctionPurchaseCallback;
	void OnCreateAuctionPurchase(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
public:
	MarketplaceHelper(ToolboxCore* core);

	OnCreateAuctionDelegate& CreateAuction(const FString& ownershipId, double startPrice, double purchasePrice);
	
	OnGetProjectAuctionsDelegate& GetProjectAuctions();
	
	OnCreateAuctionBidDelegate& CreateAuctionBid(const FString& auctionId, double price);

	OnCreateAuctionPurchaseDelegate& CreateAuctionPurchase(const FString& auctionId);
};
