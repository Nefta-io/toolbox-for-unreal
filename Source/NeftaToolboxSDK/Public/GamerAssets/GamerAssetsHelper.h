#pragma once
#include "ToolboxCore.h"

class NEFTATOOLBOXSDK_API GamerAssetsHelper
{
	ToolboxCore* Core;

	DECLARE_DELEGATE_OneParam(OnCreateCurrencyRewardForUserDelegate, bool);
	OnCreateCurrencyRewardForUserDelegate OnCreateCurrencyRewardForUserCallback;
	void OnCreateCurrencyRewardForUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	DECLARE_DELEGATE_OneParam(OnCreateAssetRewardForUserDelegate, bool);
	OnCreateAssetRewardForUserDelegate OnCreateAssetRewardForUserCallback;
	void OnCreateAssetRewardForUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
public:
	GamerAssetsHelper(ToolboxCore* core);

	OnCreateCurrencyRewardForUserDelegate& CreateCurrencyRewardForUser(FString currencyId, double amount);

	OnCreateAssetRewardForUserDelegate& CreateAssetRewardForUser(const FString& assetId);
};
