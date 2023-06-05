// Copyright 2023, Nefta, All rights reserved

#include "UserPanel.h"
#include <Components/TextBlock.h>
#include <Components/Button.h>
#include "NeftaUser.h"
#include "MainUi.h"
#include "NeftaToolboxSDK.h"

void UUserPanel::NativeConstruct()
{
	Super::NativeConstruct();

	GetUserDetailsButton->OnClicked.AddUniqueDynamic(this, &UUserPanel::OnGetUserDetails);
	UserInteractsWithAssetsButton->OnClicked.AddUniqueDynamic(this, &UUserPanel::OnUserInteractsWithAssets);
	UserInteractsWithMarketplaceButton->OnClicked.AddUniqueDynamic(this, &UUserPanel::OnUserInteractsWithMarketplace);
	UserInteractsWithCurrenciesButton->OnClicked.AddUniqueDynamic(this, &UUserPanel::OnUserInteractsWithCurrencies);
	ConvertGuestIntoFullUserButton->OnClicked.AddUniqueDynamic(this, &UUserPanel::OnConvertGuestIntoFullUser);
}

void UUserPanel::UpdateUser() const
{
	const FNeftaUser* user = FNeftaToolboxSDKModule::Get().GetUser();
	
	UsernameText->SetText(FText::FromString("Username: " + user->username));
	UserIdText->SetText(FText::FromString("UserId: " + user->user_id));
	EmailText->SetText(FText::FromString("Email: " + user->email));
	UserTokenText->SetText(FText::FromString("UserToken: " + user->user_token));

	ConvertGuestIntoFullUserButton->SetVisibility(user->email.IsEmpty() ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UUserPanel::OnGetUserDetails()
{
	UMainUi::Instance->OpenUserDetails();
}

void UUserPanel::OnUserInteractsWithAssets()
{
	UMainUi::Instance->OpenReward();
}

void UUserPanel::OnUserInteractsWithMarketplace()
{
	UMainUi::Instance->OpenMarketplace();
}

void UUserPanel::OnUserInteractsWithCurrencies()
{
	UMainUi::Instance->OpenCurrencies();
}

void UUserPanel::OnConvertGuestIntoFullUser()
{
	UMainUi::Instance->OpenConvertGuestIntoFullUser();
}
