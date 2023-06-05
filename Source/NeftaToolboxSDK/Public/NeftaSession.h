// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "NeftaUser.h"
#include "GameFramework/SaveGame.h"
#include "NeftaSession.generated.h"

UCLASS()
class NEFTATOOLBOXSDK_API UNeftaSession : public USaveGame
{
	GENERATED_BODY()

	UNeftaSession() {}

public:
	UPROPERTY(Category="Nefta Session", EditAnywhere)
	FNeftaUser User;
	
};
