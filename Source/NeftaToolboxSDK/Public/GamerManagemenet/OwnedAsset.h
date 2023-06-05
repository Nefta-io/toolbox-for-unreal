#pragma once
#include "NftAsset.h"

#include "OwnedAsset.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FOwnedAsset
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	FString ownership_id;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	FString uri;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	FString created_at;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	FString ownership_amount;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	FString purchase_price;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	int32 serial = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta Owned asset")
	UNftAsset* asset = nullptr;
};
