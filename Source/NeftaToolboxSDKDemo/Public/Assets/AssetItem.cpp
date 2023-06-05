// Copyright 2023, Nefta, All rights reserved


#include "AssetItem.h"
#include <Components/Button.h>
#include "Components/Image.h"
#include "MainUi.h"

void UAssetItem::NativeConstruct()
{
	CreateAuction->OnClicked.AddUniqueDynamic(this, &UAssetItem::OnCreateAuction);
}

void UAssetItem::Set(FOwnedAsset& asset)
{
	Asset = &asset;
	
	if (asset.asset->LoadedTexture != nullptr)
	{
		OnAssetLoaded(asset.asset);
	}
	else
	{
		asset.asset->OnLoadImageCallback.AddDynamic(this, &UAssetItem::OnAssetLoaded);
		asset.asset->LoadImage();	
	}
}

void UAssetItem::OnCreateAuction()
{
	UMainUi::Instance->OpenAuction(*Asset);
}

void UAssetItem::OnAssetLoaded(bool bWasSuccessful)
{
	Image->SetBrushFromTexture(Asset->asset->LoadedTexture, true);
}