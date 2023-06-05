#include "GamerAssetsHelper.h"
#include "JsonObjectConverter.h"
#include "RewardUserCurrencyRequest.h"
#include "Interfaces/IHttpResponse.h"

GamerAssetsHelper::GamerAssetsHelper(ToolboxCore* core)
{
	Core = core;
}

GamerAssetsHelper::OnCreateCurrencyRewardForUserDelegate& GamerAssetsHelper::CreateCurrencyRewardForUser(FString currencyId, double amount)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("CreateCurrencyRewardForUser"));
	
	FRewardUserCurrencyRequest requestBody;
	requestBody.amount = amount;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);
	
	const FString url = FString::Printf(TEXT("/gamer/currency/%s/reward"), *currencyId);
	const auto request = Core->CreatePostRequest(url, requestObject);
	    
	request->OnProcessRequestComplete().BindRaw(this, &GamerAssetsHelper::OnCreateCurrencyRewardForUser);
	request->ProcessRequest();

	return OnCreateCurrencyRewardForUserCallback;
}

void GamerAssetsHelper::OnCreateCurrencyRewardForUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnCreateCurrencyRewardForUser response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
	OnCreateCurrencyRewardForUserCallback.Execute(bWasSuccessful);
}


GamerAssetsHelper::OnCreateAssetRewardForUserDelegate& GamerAssetsHelper::CreateAssetRewardForUser(const FString& assetId)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("CreateAssetRewardForUser"));

	const FString url = FString::Printf(TEXT("/gamer/asset/%s/reward"), *assetId);
	const auto request = Core->CreatePostRequest(url, nullptr);

	request->OnProcessRequestComplete().BindRaw(this, &GamerAssetsHelper::OnCreateAssetRewardForUser);
	request->ProcessRequest();

	return OnCreateAssetRewardForUserCallback;
}

void GamerAssetsHelper::OnCreateAssetRewardForUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnCreateAssetRewardForUser response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;

	OnCreateAssetRewardForUserCallback.Execute(bWasSuccessful);
}