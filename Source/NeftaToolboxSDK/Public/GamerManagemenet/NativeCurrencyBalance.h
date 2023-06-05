#pragma once

#include "NativeCurrencyBalance.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FNativeCurrencyBalance
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta Native currency")
	double coin_balance = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Native currency")
	FString coin_balance_name;
};
