// Copyright 2023, Nefta, All rights reserved

#include "RewardPanel.h"
#include "NeftaToolboxSDK.h"
#include <Components/Button.h>
#include "Components/EditableText.h"
#include "MainUi.h"

void URewardPanel::NativeConstruct()
{
	Super::NativeConstruct();

	Reward->OnClicked.AddUniqueDynamic(this, &URewardPanel::OnReward);
	Close->OnClicked.AddUniqueDynamic(this, &URewardPanel::OnClose);
}

void URewardPanel::OnReward()
{
	const auto assetId = AssetId->GetText().ToString();
	FNeftaToolboxSDKModule::Get().GamerAssets->CreateAssetRewardForUser(assetId)
		.BindUObject(this, &URewardPanel::OnRewardComplete);
}

void URewardPanel::OnRewardComplete(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UMainUi::Instance->OpenAssets();
	}
}

void URewardPanel::OnClose()
{
	UMainUi::Instance->OpenUser();
}


