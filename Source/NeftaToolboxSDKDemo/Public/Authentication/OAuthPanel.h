// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuthenticationPanel.h"
#include "OAuthPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UOAuthPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	UButton* Close;

	UFUNCTION()
	void OnClose();

	UAuthenticationPanel* AuthenticationPanel;

public:
	void Init(UAuthenticationPanel* authenticationPanel);
	
};
