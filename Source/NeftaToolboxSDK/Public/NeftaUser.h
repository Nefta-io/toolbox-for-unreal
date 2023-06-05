#pragma once

#include "NeftaUser.generated.h"

USTRUCT(BlueprintType)
struct NEFTATOOLBOXSDK_API FNeftaUser
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta user")
	FString user_token;
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta user")
	FString user_id;
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta user")
	FString username;
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta user")
	FString email;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta user")
	FString address;
	
	bool IsValid() const;
};
