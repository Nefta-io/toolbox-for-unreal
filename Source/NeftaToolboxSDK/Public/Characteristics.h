#pragma once

#include "Characteristics.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FCharacteristics
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	FString currency; // parameter with "nft_staking"
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	FString currency_id; // parameter with "nft_staking"
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	FString principal_amount; // parameter with "nft_staking"

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	float interest = 0; // parameter with "nft_staking". Interest earned per day based on principal   

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	int32 days_to_self_destruct = 0; // parameter with "timed_assets"
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	int32 hours_to_self_destruct = 0; // parameter with "timed_assets"
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	int32 minute_to_self_destruct = 0; // parameter with "timed_assets" 

	//public int rental_period;  // parameter with "rentable"
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	FString rental_period_type; // parameter with "rentable" can be "day" or "month"

	// The following are booleans indicating the present characteristics of the asset
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	bool nft_staking = false;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	bool burnable = false;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	bool rentable = false;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	bool timed_assets = false;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT Characteristics")
	bool evolvable = false;
};
