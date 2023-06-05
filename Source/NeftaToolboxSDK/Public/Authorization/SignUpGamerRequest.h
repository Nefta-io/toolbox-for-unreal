#pragma once

#include "SignUpGamerRequest.generated.h"

USTRUCT()
struct FSignUpGamerRequest
{
	GENERATED_BODY()
    
	UPROPERTY()
	FString public_project_id;
	
	UPROPERTY()
	FString email;
	
	UPROPERTY()
	FString username;
};
