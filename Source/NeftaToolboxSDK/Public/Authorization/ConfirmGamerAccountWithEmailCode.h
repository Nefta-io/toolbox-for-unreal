#pragma once

#include "ConfirmGamerAccountWithEmailCode.generated.h"

USTRUCT()
struct FConfirmGamerAccountWithEmailCode
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString email;
	UPROPERTY()
	FString code;
};
