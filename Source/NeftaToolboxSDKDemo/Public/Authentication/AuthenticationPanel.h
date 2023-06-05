// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuthenticationPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAuthenticationPanel : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    UPROPERTY (meta = (BindWidget))
    class UWidgetSwitcher* AuthenticationSwitcher;
    
    UPROPERTY (meta = (BindWidget))
    class UIntroPanel* IntroPanel;

	UPROPERTY (meta = (BindWidget))
	class UOAuthPanel* OAuthPanel;
    
    UPROPERTY (meta = (BindWidget))
    class UGuestPanel* GuestPanel;

	UPROPERTY (meta = (BindWidget))
	class UFullUserPanel* FullUserPanel;

	UPROPERTY (meta = (BindWidget))
	class UConvertGuestIntoFullUserPanel* ConvertGuestIntoFullUserPanel;

	UPROPERTY (meta = (BindWidget))
	class UConfirmEmailPanel* ConfirmEmailPanel;

	UPROPERTY (meta = (BindWidget))
	class ULoginPanel* LoginPanel;

	UPROPERTY (meta = (BindWidget))
	class ULoginConfirmPanel* LoginConfirmPanel;

	void NativeConstruct() override;
    
public:
	
    void Init();

	void OpenIntro();

	void OpenOAuth();

	void OpenGuest();

	void OpenFullUser();

	void OpenConvertGuestIntoFullUser();

	void OpenConfirmEmail(FString email);

	void OpenLogin();

	void OpenLoginConfirm(FString email);
};
