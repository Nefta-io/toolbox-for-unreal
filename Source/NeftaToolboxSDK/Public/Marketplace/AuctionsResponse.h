// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "Auction.h"
#include "AuctionsResponse.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FAuctionsResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<FAuction> results;

	UPROPERTY(BlueprintReadOnly)
	int32 page = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 perPage = 0;

	UPROPERTY(BlueprintReadOnly)
	int count = 0;
	
};
