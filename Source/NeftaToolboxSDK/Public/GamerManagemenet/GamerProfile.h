#pragma once

#include "GamerProfile.generated.h"

USTRUCT()
struct NEFTATOOLBOXSDK_API FGamerProfile
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString user_id;

	UPROPERTY()
	FString username;

	UPROPERTY()
	FString address;
};
