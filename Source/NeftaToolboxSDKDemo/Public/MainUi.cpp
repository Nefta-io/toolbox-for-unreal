// Copyright 2023, Nefta, All rights reserved


#include "MainUi.h"

#include "NeftaToolboxSDK.h"
#include "Authentication/AuthenticationPanel.h"
#include "User/UserPanel.h"
#include "UserDetails/UserDetailsPanel.h"
#include "Assets/AssetsPanel.h"
#include "Auction/AuctionPanel.h"
#include "Reward/RewardPanel.h"
#include "Components/WidgetSwitcher.h"
#include "Marketplace/MarketplacePanel.h"
#include "Auction/AuctionsPanel.h"
#include "Currencies/CurrenciesPanel.h"
#include "Kismet/GameplayStatics.h"

UMainUi* UMainUi::Instance;

void UMainUi::NativeConstruct()
{
    Super::NativeConstruct();

    Instance = this;

    UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
    
    FNeftaToolboxSDKModule::Get().Init();
    
    FNeftaUser* user = FNeftaToolboxSDKModule::Get().GetUser();
    if (user != nullptr && user->IsValid())
    {
        OpenUser();
    }
}

void UMainUi::OpenUser()
{
    MainSwitcher->SetActiveWidget(UserPanel);
    UserPanel->UpdateUser();
}

void UMainUi::OpenUserDetails()
{
    MainSwitcher->SetActiveWidget(UserDetailsPanel);
    UserDetailsPanel->UpdateProfile();
}

void UMainUi::OpenAssets()
{
    MainSwitcher->SetActiveWidget(AssetsPanel);
    AssetsPanel->UpdateAssets();
}

void UMainUi::OpenConvertGuestIntoFullUser()
{
    MainSwitcher->SetActiveWidget(AuthenticationPanel);
    AuthenticationPanel->OpenConvertGuestIntoFullUser();
}

void UMainUi::OpenReward()
{
    MainSwitcher->SetActiveWidget(RewardPanel);
}

void UMainUi::OpenAuction(FOwnedAsset& asset)
{
    MainSwitcher->SetActiveWidget(AuctionPanel);
    AuctionPanel->Show(asset);
}

void UMainUi::OpenCurrencies()
{
    MainSwitcher->SetActiveWidget(CurrenciesPanel);
    CurrenciesPanel->OpenOptions();
}

void UMainUi::OpenMarketplace()
{
    MainSwitcher->SetActiveWidget(MarketplacePanel);
}

void UMainUi::OpenAuctions()
{
    MainSwitcher->SetActiveWidget(AuctionsPanel);
    AuctionsPanel->Show();
}
