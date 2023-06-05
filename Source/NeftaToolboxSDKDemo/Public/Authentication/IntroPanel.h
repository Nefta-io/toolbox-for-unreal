// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IntroPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UIntroPanel : public UUserWidget
{
	GENERATED_BODY()
protected:

	UPROPERTY ( meta = (BindWidget))
	class UButton* SignUpAsGuest;
	
	UPROPERTY ( meta = (BindWidget))
	UButton* GoogleSignUp;

	UPROPERTY ( meta = (BindWidget))
	UButton* AppleSignUp;
	
	UPROPERTY ( meta = (BindWidget))
	UButton* FacebookSignUp;
    
	UPROPERTY ( meta = (BindWidget))
	UButton* TwitchSignUp;
    
	UPROPERTY ( meta = (BindWidget))
	UButton* SignUpAsFullUser;
    
	UPROPERTY ( meta = (BindWidget))
	UButton* Login;

	UFUNCTION()
	void OnSignUpWithGoogle();

	UFUNCTION()
	void OnSignUpWithApple();

	UFUNCTION()
	void OnSignUpWithFacebook();

	UFUNCTION()
	void OnSignUpWithTwitch();
	
	UFUNCTION()
	void OnSignUpAsGuest();
    
	UFUNCTION()
	void OnSignUpAsFullUser();
    
	UFUNCTION()
	void OnLogin();
	
	class UAuthenticationPanel* AuthenticationPanel;
    
public:
	void Init(UAuthenticationPanel* authenticationPanel);
};
