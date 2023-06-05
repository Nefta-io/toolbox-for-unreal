#include "MarketplaceHelper.h"
#include "CreateAuctionBidRequest.h"
#include "CreateGamerBuyAuctionRequest.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"

MarketplaceHelper::MarketplaceHelper(ToolboxCore* core)
{
	Core = core;
}

MarketplaceHelper::OnCreateAuctionDelegate& MarketplaceHelper::CreateAuction(const FString& ownershipId, double startPrice, double purchasePrice)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("CreateAuction"));

	FCreateGamerBuyAuctionRequest requestBody = FCreateGamerBuyAuctionRequest();
	requestBody.ownership_id = ownershipId;
	requestBody.auction_type = "standard_auction";
	requestBody.start_price = startPrice;
	if (purchasePrice > 0)
	{
		requestBody.purchase_price = purchasePrice;
	}
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);
	const auto request = Core->CreatePostRequest("/gamer/auction", requestObject);

	request->OnProcessRequestComplete().BindRaw(this, &MarketplaceHelper::OnCreateAuction);
	request->ProcessRequest();

	return OnCreateAuctionCallback;
}

void MarketplaceHelper::OnCreateAuction(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnCreateAuction response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;

	OnCreateAuctionCallback.Execute(bWasSuccessful);
}

MarketplaceHelper::OnGetProjectAuctionsDelegate& MarketplaceHelper::GetProjectAuctions()
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GetProjectAuctions"));

	const auto url = FString::Printf(TEXT("/auctions?mid=%s"), *FString(Core->MarketplaceId));
	const auto request = Core->CreateGetRequest(url);

	request->OnProcessRequestComplete().BindRaw(this, &MarketplaceHelper::OnGetProjectAuctions);
	request->ProcessRequest();

	return OnGetProjectAuctionsCallback;
}

void MarketplaceHelper::OnGetProjectAuctions(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FAuctionsResponse* auctionsResponse = new FAuctionsResponse; 
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGetProjectAuctions response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300) {
		FJsonObjectConverter::JsonObjectStringToUStruct<FAuctionsResponse>(responseBody, auctionsResponse, 0, 0);
		for (int32 i = 0; i < auctionsResponse->results.Num(); i++)
		{
			auctionsResponse->results[i].asset->Init();
		}
	}

	OnGetProjectAuctionsCallback.Execute(*auctionsResponse);
}

MarketplaceHelper::OnCreateAuctionBidDelegate& MarketplaceHelper::CreateAuctionBid(const FString& auctionId, double price)
{
	UE_LOG(LogTemp, Log, TEXT("CreateAuctionBid"));
	
	const auto url = FString::Printf(TEXT("/gamer/auction/%s/bid"), *FString(auctionId));
	FCreateAuctionBidRequest requestBody = FCreateAuctionBidRequest();
	requestBody.bid_price = price;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);
	const auto request = Core->CreatePostRequest(url, requestObject);

	request->OnProcessRequestComplete().BindRaw(this, &MarketplaceHelper::OnCreateAuctionBid);
	request->ProcessRequest();

	return OnCreateAuctionBidCallback;
}

void MarketplaceHelper::OnCreateAuctionBid(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnCreateAuctionBid response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
	OnCreateAuctionBidCallback.Execute(bWasSuccessful);
}

MarketplaceHelper::OnCreateAuctionPurchaseDelegate& MarketplaceHelper::CreateAuctionPurchase(const FString& auctionId)
{
	UE_LOG(LogTemp, Log, TEXT("CreateAuctionPurchase"));

	const auto url = FString::Printf(TEXT("/gamer/auction/%s/purchase"), *FString(auctionId));
	const auto request = Core->CreatePostRequest(url, nullptr);

	request->OnProcessRequestComplete().BindRaw(this, &MarketplaceHelper::OnCreateAuctionPurchase);
	request->ProcessRequest();

	return OnCreateAuctionPurchaseCallback;
}

void MarketplaceHelper::OnCreateAuctionPurchase(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnCreateAuctionPurchase response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
	OnCreateAuctionPurchaseCallback.Execute(bWasSuccessful);
}