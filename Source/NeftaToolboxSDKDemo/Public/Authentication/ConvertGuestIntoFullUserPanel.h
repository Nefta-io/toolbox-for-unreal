// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConvertGuestIntoFullUserPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UConvertGuestIntoFullUserPanel : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY ( meta = (BindWidget))
	class UEditableText* EmailInputText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* ConfirmButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	UFUNCTION()
	void OnConfirm();

	UFUNCTION()
	void OnConfirmComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();
	
	class UAuthenticationPanel* AuthenticationPanel;

	UPROPERTY()
	FString Email;
	
public:
	void Init(UAuthenticationPanel* authenticationPanel);

};
