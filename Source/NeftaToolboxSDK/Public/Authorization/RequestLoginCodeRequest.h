#pragma once

#include "RequestLoginCodeRequest.generated.h"

USTRUCT()
struct FRequestLoginCodeRequest
{
	GENERATED_BODY()

	UPROPERTY()
	FString email;
};