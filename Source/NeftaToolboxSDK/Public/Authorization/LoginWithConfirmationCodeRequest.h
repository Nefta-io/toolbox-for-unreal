#pragma once

#include "LoginWithConfirmationCodeRequest.generated.h"

USTRUCT()
struct FLoginWithConfirmationCodeRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString email;
	UPROPERTY()
	FString code;
};
