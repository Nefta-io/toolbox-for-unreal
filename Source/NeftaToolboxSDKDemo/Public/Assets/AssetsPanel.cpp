// Copyright 2023, Nefta, All rights reserved


#include "AssetsPanel.h"

#include <Components/Button.h>
#include <Components/ScrollBox.h>

#include "AssetItem.h"
#include "NeftaToolboxSDK.h"
#include "Components/Image.h"
#include "MainUi.h"

void UAssetsPanel::NativeConstruct()
{
	Close->OnClicked.AddUniqueDynamic(this, &UAssetsPanel::OnClose);
}

void UAssetsPanel::UpdateAssets()
{
	FNeftaToolboxSDKModule::Get().GamerManagement->GetGamerOwnedAssets()
		.BindUObject(this, &UAssetsPanel::OnUpdateAssets);
}

void UAssetsPanel::OnUpdateAssets(FOwnedAssetsResponse& assetsResponse)
{
	AssetList->ClearChildren();
	
	for (int32 i = 0; i < assetsResponse.results.Num(); i++)
	{
		UAssetItem* assetItem = CreateWidget<UAssetItem>(this, AssetItemPrefab);
		AssetList->AddChild(assetItem);
		assetItem->Set(assetsResponse.results[i]);
	}
}

void UAssetsPanel::OnClose()
{
	UMainUi::Instance->OpenUserDetails();
}