// Copyright 2023, Nefta, All rights reserved


#include "MarketplacePanel.h"
#include <Components/Button.h>
#include "MainUi.h"

void UMarketplacePanel::NativeConstruct()
{
	Super::NativeConstruct();

	GetAuctions->OnClicked.AddUniqueDynamic(this, &UMarketplacePanel::OnGetAuctions);
	Close->OnClicked.AddUniqueDynamic(this, &UMarketplacePanel::OnClose);
}

void UMarketplacePanel::OnGetAuctions()
{
	UMainUi::Instance->OpenAuctions();
}

void UMarketplacePanel::OnClose()
{
	UMainUi::Instance->OpenUser();
}