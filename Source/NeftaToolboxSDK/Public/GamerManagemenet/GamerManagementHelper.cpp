#include "GamerManagementHelper.h"
#include "GamerProfile.h"
#include "CurrencyBalance.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"

GamerManagementHelper::GamerManagementHelper(ToolboxCore* core)
{
	Core = core;
}

GamerManagementHelper::OnGetGamerProfileDelegate& GamerManagementHelper::GetGamerProfile()
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GetGamerProfile"));

	const auto request = Core->CreateGetRequest("/gamer/profile");

	request->OnProcessRequestComplete().BindRaw(this, &GamerManagementHelper::OnGetGamerProfile);
	request->ProcessRequest();

	return OnGetGamerProfileCallback;
}

void GamerManagementHelper::OnGetGamerProfile(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FGamerProfile* profile = new FGamerProfile;
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGetGamerProfile response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300) {
		bWasSuccessful = FJsonObjectConverter::JsonObjectStringToUStruct<FGamerProfile>(responseBody, profile, 0, 0);
		Core->GetUser()->address = profile->address;
		Core->SaveSession();
	}

	OnGetGamerProfileCallback.Execute(bWasSuccessful);
}

GamerManagementHelper::OnGetGamerOwnedAssetsDelegate& GamerManagementHelper::GetGamerOwnedAssets()
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GetGamerOwnedAssets"));

	const auto request = Core->CreateGetRequest("/gamer/assets");

	request->OnProcessRequestComplete().BindRaw(this, &GamerManagementHelper::OnGetGamerOwnedAssets);
	request->ProcessRequest();

	return OnGetGamerOwnedAssetsCallback;
}

void GamerManagementHelper::OnGetGamerOwnedAssets(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FOwnedAssetsResponse* ownedAssetsResponse = new FOwnedAssetsResponse;; 
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGetGamerOwnedAssets response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300) {
		FJsonObjectConverter::JsonObjectStringToUStruct<FOwnedAssetsResponse>(responseBody, ownedAssetsResponse, 0, 0);
		for (int32 i = 0; i < ownedAssetsResponse->results.Num(); i++)
		{
			ownedAssetsResponse->results[i].asset->Init();
		}
	}

	OnGetGamerOwnedAssetsCallback.Execute(*ownedAssetsResponse);
}

GamerManagementHelper::OnGetGamerCryptoBalanceDelegate& GamerManagementHelper::GetGamerCryptoBalance()
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GetGamerCryptoBalance"));
	
	const auto request = Core->CreateGetRequest("/gamer/currencies");
	request->OnProcessRequestComplete().BindRaw(this, &GamerManagementHelper::OnGetGamerCryptoBalance);
	request->ProcessRequest();

	return OnGetGamerCryptoBalanceCallback;
}

void GamerManagementHelper::OnGetGamerCryptoBalance(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FNativeCurrencyBalance* balance = new FNativeCurrencyBalance;
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGetGamerCryptoBalance response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300)
	{
		bWasSuccessful = FJsonObjectConverter::JsonObjectStringToUStruct<FNativeCurrencyBalance>(responseBody, balance, 0, 0);
	}
	else
	{
		bWasSuccessful = false;
	}

	OnGetGamerCryptoBalanceCallback.Execute(bWasSuccessful, *balance);
}

GamerManagementHelper::OnGetGamerCurrencyBalanceDelegate& GamerManagementHelper::GetGamerCurrencyBalance(const FString& currencyId)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GetGamerCurrencyBalance"));

	const FString url = FString::Printf(TEXT("/gamer/currencies/%s"), *currencyId);
	const auto request = Core->CreateGetRequest(url);

	request->OnProcessRequestComplete().BindRaw(this, &GamerManagementHelper::OnGetGamerCurrencyBalance);
	request->ProcessRequest();

	return OnGetGamerCurrencyBalanceCallback;
}

void GamerManagementHelper::OnGetGamerCurrencyBalance(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FCurrencyBalance* balance = new FCurrencyBalance;
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGetGamerCurrencyBalance response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300)
	{
		bWasSuccessful = FJsonObjectConverter::JsonObjectStringToUStruct<FCurrencyBalance>(responseBody, balance, 0, 0);
	}
	else
	{
		bWasSuccessful = false;
	}

	OnGetGamerCurrencyBalanceCallback.Execute(bWasSuccessful, *balance);
}