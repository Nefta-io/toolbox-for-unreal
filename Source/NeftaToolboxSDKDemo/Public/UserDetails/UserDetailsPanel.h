// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamerManagemenet/GamerProfile.h"
#include "GamerManagemenet/NativeCurrencyBalance.h"
#include "UserDetailsPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UUserDetailsPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UTextBlock* AddressText;

	UPROPERTY ( meta = (BindWidget))
	UTextBlock* BalanceText;

	UPROPERTY ( meta = (BindWidget))
	class UButton* GetUserProfileButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* GetOwnedAssetsButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* GetGamerCryptoBalanceButton;

	UPROPERTY ( meta = (BindWidget))
	UButton* CloseButton;

	void NativeConstruct() override;

	UFUNCTION()
	void OnGetUserProfile();

	UFUNCTION()
	void OnGetUserProfileComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnGetOwnedAssets();

	UFUNCTION()
	void OnGetGamerCryptoBalance();

	UFUNCTION()
	void OnGetGamerCryptoBalanceComplete(bool bWasSuccessful, FNativeCurrencyBalance& balance) const;

	UFUNCTION()
	void OnClose();

public:
	UFUNCTION()
	void UpdateProfile() const;
};
