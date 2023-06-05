// Copyright 2023, Nefta, All rights reserved

#include "UserDetailsPanel.h"
#include <Components/TextBlock.h>
#include <Components/Button.h>
#include "NeftaToolboxSDK.h"
#include "MainUi.h"

void UUserDetailsPanel::NativeConstruct()
{
	Super::NativeConstruct();
    
	GetUserProfileButton->OnClicked.AddUniqueDynamic(this, &UUserDetailsPanel::OnGetUserProfile);
	GetOwnedAssetsButton->OnClicked.AddUniqueDynamic(this, &UUserDetailsPanel::OnGetOwnedAssets);
	GetGamerCryptoBalanceButton->OnClicked.AddUniqueDynamic(this, &UUserDetailsPanel::OnGetGamerCryptoBalance);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UUserDetailsPanel::OnClose);
}

void UUserDetailsPanel::OnGetUserProfile()
{
	FNeftaToolboxSDKModule::Get().GamerManagement->GetGamerProfile()
		.BindUObject(this, &UUserDetailsPanel::OnGetUserProfileComplete);
}

void UUserDetailsPanel::OnGetUserProfileComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UpdateProfile();
	}
}

void UUserDetailsPanel::OnGetOwnedAssets()
{
	UMainUi::Instance->OpenAssets();
}

void UUserDetailsPanel::OnGetGamerCryptoBalance()
{
	FNeftaToolboxSDKModule::Get().GamerManagement->GetGamerCryptoBalance()
		.BindUObject(this, &UUserDetailsPanel::OnGetGamerCryptoBalanceComplete);
}

void UUserDetailsPanel::OnGetGamerCryptoBalanceComplete(bool bWasSuccessful, FNativeCurrencyBalance& balance) const
{
	if (bWasSuccessful)
	{
		BalanceText->SetText(FText::FromString(FString::Printf(TEXT("balance: %s %g"), *balance.coin_balance_name, balance.coin_balance)));
	}
}

void UUserDetailsPanel::OnClose()
{
	UMainUi::Instance->OpenUser();
}

void UUserDetailsPanel::UpdateProfile() const
{
	const auto user = FNeftaToolboxSDKModule::Get().GetUser();
	AddressText->SetText(FText::FromString("Address: " + user->address));
}
