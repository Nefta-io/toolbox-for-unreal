#pragma once

#include "CurrencyBalance.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FCurrencyBalance
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta currency balance")
	double balance = 0;
};