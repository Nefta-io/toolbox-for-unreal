#pragma once
#include "NftAsset.h"

#include "Auction.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FAuction
{
	GENERATED_BODY()
    
	UPROPERTY(BlueprintReadOnly)
	int32 serial = 0;

	UPROPERTY(BlueprintReadOnly)
	FString auction_type;
	
	UPROPERTY(BlueprintReadOnly)
	FString purchase_price;

	UPROPERTY(BlueprintReadOnly)
	FString sell_price;

	UPROPERTY(BlueprintReadOnly)
	FString sell_date;

	UPROPERTY(BlueprintReadOnly)
	FString start_price;

	UPROPERTY(BlueprintReadOnly)
	FString end_date;

	UPROPERTY(BlueprintReadOnly)
	FString auction_id;

	UPROPERTY(BlueprintReadOnly)
	FString start_date;

	UPROPERTY(BlueprintReadOnly)
	bool user_auctions = false;

	UPROPERTY(BlueprintReadOnly)
	FString status;

	UPROPERTY(BlueprintReadOnly)
	FString number_of_bids;

	UPROPERTY(BlueprintReadOnly)
	FString last_bid_price;

	UPROPERTY(BlueprintReadOnly)
	UNftAsset* asset = nullptr;
};
