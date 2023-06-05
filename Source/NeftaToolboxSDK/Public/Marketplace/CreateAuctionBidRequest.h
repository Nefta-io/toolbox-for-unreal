#pragma once

#include "CreateAuctionBidRequest.generated.h"

USTRUCT()
struct FCreateAuctionBidRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	double bid_price = 0;
};
