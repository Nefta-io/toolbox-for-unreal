// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UUserPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UTextBlock* UsernameText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* UserIdText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* EmailText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* UserTokenText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* GetUserDetailsButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* UserInteractsWithAssetsButton;
	
	UPROPERTY ( meta = (BindWidget))
	UButton* UserInteractsWithMarketplaceButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* UserInteractsWithCurrenciesButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* ConvertGuestIntoFullUserButton;

	UFUNCTION()
	void OnGetUserDetails();

	UFUNCTION()
	void OnUserInteractsWithAssets();

	UFUNCTION()
	void OnUserInteractsWithMarketplace();

	UFUNCTION()
	void OnUserInteractsWithCurrencies();

	UFUNCTION()
	void OnConvertGuestIntoFullUser();

	void NativeConstruct() override;

public:
	void UpdateUser() const;
};
