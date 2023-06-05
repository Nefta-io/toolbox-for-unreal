#pragma once

#include "SignupGuestUserRequest.generated.h"

USTRUCT()
struct FSignupGuestUserRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString public_project_id;
	UPROPERTY()
	FString username;
};
