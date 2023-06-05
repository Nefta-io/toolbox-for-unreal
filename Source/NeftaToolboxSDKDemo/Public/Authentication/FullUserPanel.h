// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FullUserPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UFullUserPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UEditableText* Username;

	UPROPERTY ( meta = (BindWidget))
	UEditableText* Email;

	UPROPERTY ( meta = (BindWidget))
	class UButton* SignUp;

	UPROPERTY ( meta = (BindWidget))
	UButton* Close;

	FString UserEmail;

	UFUNCTION()
	void OnSignUp();

	void OnSignUpComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();

	class UAuthenticationPanel* AuthenticationPanel;

public:
	void Init(UAuthenticationPanel* authenticationPanel);
};
