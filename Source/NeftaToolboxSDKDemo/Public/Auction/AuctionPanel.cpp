// Copyright 2023, Nefta, All rights reserved

#include "AuctionPanel.h"
#include <Components/Button.h>
#include "NeftaToolboxSDKDemo.h"
#include "Components/EditableText.h"
#include "Misc/DefaultValueHelper.h"
#include "MainUi.h"

void UAuctionPanel::NativeConstruct()
{
	Super::NativeConstruct();

	CreateAuctionButton->OnClicked.AddUniqueDynamic(this, &UAuctionPanel::OnCreateAuction);
	CloseButton->OnClicked.AddUniqueDynamic(this, &UAuctionPanel::OnClose);
}

void UAuctionPanel::Show(FOwnedAsset& asset)
{
	Asset = &asset;
}

void UAuctionPanel::OnCreateAuction()
{
	double startPrice = 0;
	double purchasePrice = 0;
	if (!StartPriceText->GetText().IsEmpty())
	{
		FDefaultValueHelper::ParseDouble(*StartPriceText->GetText().ToString(), startPrice);
	}
	if (!PurchasePriceText->GetText().IsEmpty())
	{
		FDefaultValueHelper::ParseDouble(*PurchasePriceText->GetText().ToString(), purchasePrice);
	}

	if (startPrice > 0)
	{
		FNeftaToolboxSDKModule::Get().Marketplace->CreateAuction(Asset->ownership_id, startPrice, purchasePrice)
			.BindUObject(this, &UAuctionPanel::OnCreateAuctionComplete);
	}
	else
	{
		UE_LOG(LogNeftaDemo, Log, TEXT("Enter auction price"));
	}
}

void UAuctionPanel::OnCreateAuctionComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UMainUi::Instance->OpenMarketplace();
	}
}


void UAuctionPanel::OnClose()
{
	UMainUi::Instance->OpenAssets();
}