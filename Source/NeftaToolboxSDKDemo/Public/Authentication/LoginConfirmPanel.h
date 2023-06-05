// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginConfirmPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API ULoginConfirmPanel : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY ( meta = (BindWidget))
	class UEditableText* ConfirmationCode;

	UPROPERTY ( meta = (BindWidget))
	class UButton* Confirm;

	UFUNCTION()
	void OnConfirm();

	void OnConfirmComplete(struct FNeftaUser& neftaUser);
	
	class UAuthenticationPanel* AuthenticationPanel;

	FString Email;

public:
	void Init(UAuthenticationPanel* authenticationPanel);

	void SetEmail(FString email);
};
