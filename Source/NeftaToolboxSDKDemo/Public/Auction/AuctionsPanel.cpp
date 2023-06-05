// Copyright 2023, Nefta, All rights reserved

#include "AuctionsPanel.h"
#include <Components/Button.h>
#include "AuctionItem.h"
#include "NeftaToolboxSDK.h"
#include "Components/ScrollBox.h"
#include "MainUi.h"

void UAuctionsPanel::NativeConstruct()
{
	Super::NativeConstruct();
	
	Close->OnClicked.AddUniqueDynamic(this, &UAuctionsPanel::OnClose);
}

void UAuctionsPanel::Show()
{
	FNeftaToolboxSDKModule::Get().Marketplace->GetProjectAuctions()
	.BindUObject(this, &UAuctionsPanel::ShowComplete);
}

void UAuctionsPanel::ShowComplete(FAuctionsResponse& auctionsResponse)
{
	AuctionList->ClearChildren();

	for (int32 i = 0; i < auctionsResponse.results.Num(); i++)
	{
		UAuctionItem* auctionItem = CreateWidget<UAuctionItem>(this, AuctionItemPrefab);
		AuctionList->AddChild(auctionItem);
		auctionItem->Set(auctionsResponse.results[i]);
	}
}

void UAuctionsPanel::OnClose()
{
	UMainUi::Instance->OpenMarketplace();
}

