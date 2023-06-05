// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API ULoginPanel : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY ( meta = (BindWidget))
	class UEditableText* Email;

	UPROPERTY ( meta = (BindWidget))
	class UButton* Confirm;

	UPROPERTY ( meta = (BindWidget))
	UButton* Close;

	UFUNCTION()
	void OnConfirm();

	void OnConfirmComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();
	
	class UAuthenticationPanel* AuthenticationPanel;

	FString SigningEmail;

public:
	void Init(UAuthenticationPanel* authenticationPanel);
};
