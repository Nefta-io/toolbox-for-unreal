#pragma once
#include "OwnedAsset.h"

#include "OwnedAssetsResponse.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FOwnedAssetsResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	TArray<FOwnedAsset> results;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	int32 page = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	int32 perPage = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	int count = 0;
	
};
