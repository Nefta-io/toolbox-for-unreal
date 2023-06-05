#pragma once
#include "CurrencyBalance.h"
#include "NativeCurrencyBalance.h"
#include "OwnedAssetsResponse.h"
#include "ToolboxCore.h"

class NEFTATOOLBOXSDK_API GamerManagementHelper
{
	ToolboxCore* Core;

	DECLARE_DELEGATE_OneParam(OnGetGamerProfileDelegate, bool);
	OnGetGamerProfileDelegate OnGetGamerProfileCallback;
	void OnGetGamerProfile(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	DECLARE_DELEGATE_OneParam(OnGetGamerOwnedAssetsDelegate, FOwnedAssetsResponse&);
	OnGetGamerOwnedAssetsDelegate OnGetGamerOwnedAssetsCallback;
	void OnGetGamerOwnedAssets(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	DECLARE_DELEGATE_TwoParams(OnGetGamerCryptoBalanceDelegate, bool, FNativeCurrencyBalance&);
	OnGetGamerCryptoBalanceDelegate OnGetGamerCryptoBalanceCallback;
	void OnGetGamerCryptoBalance(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_TwoParams(OnGetGamerCurrencyBalanceDelegate, bool, FCurrencyBalance&);
	OnGetGamerCurrencyBalanceDelegate OnGetGamerCurrencyBalanceCallback;
	void OnGetGamerCurrencyBalance(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
public:
	GamerManagementHelper(ToolboxCore* core);
	
	OnGetGamerProfileDelegate& GetGamerProfile();

	OnGetGamerOwnedAssetsDelegate& GetGamerOwnedAssets();

	OnGetGamerCryptoBalanceDelegate& GetGamerCryptoBalance();

	OnGetGamerCurrencyBalanceDelegate& GetGamerCurrencyBalance(const FString& currencyId);
};
