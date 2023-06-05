// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AuthenticationPanel.h"
#include "Blueprint/UserWidget.h"
#include "GuestPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UGuestPanel : public UUserWidget
{
	GENERATED_BODY()
    
protected:
    UPROPERTY ( meta = (BindWidget))
    class UEditableText* GuestName;
    
    UPROPERTY ( meta = (BindWidget))
    class UButton* SignUpGuest;
    
    UPROPERTY ( meta = (BindWidget))
	UButton* Close;
    
    UFUNCTION()
    void OnSignUpGuest();
    
    UFUNCTION()
    void OnClose();
	
	void OnSignUpGuestComplete(struct FNeftaUser& neftaUser);
    
	UAuthenticationPanel* AuthenticationPanel;
    
public:
    void Init(UAuthenticationPanel* authenticationPanel);
	
};
