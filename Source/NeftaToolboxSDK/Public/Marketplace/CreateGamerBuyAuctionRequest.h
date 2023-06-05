#pragma once

#include "CreateGamerBuyAuctionRequest.generated.h"

USTRUCT()
struct FCreateGamerBuyAuctionRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString ownership_id;

	UPROPERTY()
	FString auction_type;

	UPROPERTY()
	double start_price = 0;

	UPROPERTY()
	double purchase_price = 0;
};
