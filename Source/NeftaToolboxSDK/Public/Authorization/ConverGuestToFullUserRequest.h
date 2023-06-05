#pragma once

#include "ConverGuestToFullUserRequest.generated.h"

USTRUCT()
struct FConvertGuestToFullUserRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString email;
};
