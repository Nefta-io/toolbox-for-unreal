// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "NeftaToolboxSDK.h"
#include "NeftaToolbox.generated.h"

UCLASS(Blueprintable)
class NEFTATOOLBOXSDK_API UNeftaToolbox : public UObject
{
	GENERATED_BODY()

	FNeftaToolboxSDKModule* Sdk;
	
	void OnSignUpGuestUser(FNeftaUser& user) const;
	void OnSignUpGamer(bool bWasSuccessful) const;
	void OnRequestLoginCode(bool bWasSuccessful) const;
	void OnLoginWithConfirmationCode(FNeftaUser& user) const;
	void OnGuestFullSignup(bool bWasSuccessful) const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSignUpGuestUser, bool, bWasSuccessful, const FNeftaUser&, user);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSignUpGamer, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestLoginCode, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoginWithConfirmationCode, bool, bWasSuccessful, const FNeftaUser&, user);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuestFullSignup, bool, bWasSuccessful, const FNeftaUser&, user);

	
	void OnCreateCurrencyRewardForUser(bool bWasSuccessful) const;
	void OnCreateAssetRewardForUser(bool bWasSuccessful) const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateCurrencyRewardForUser, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateAssetRewardForUser, bool, bWasSuccessful);


	void OnGetGamerProfile(bool bWasSuccessful) const;
	void OnGetGamerOwnedAssets(FOwnedAssetsResponse& assetsResponse);
	void OnGetGamerCryptoBalance(bool bWasSuccessful, FNativeCurrencyBalance& nativeBalance) const;
	void OnGetGamerCurrencyBalance(bool bWasSuccessful, FCurrencyBalance& currencyBalance) const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetGamerProfile, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetGamerOwnedAssets, const FOwnedAssetsResponse&, assetsResponse);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetGamerCryptoBalance, bool, bWasSuccesful, const FNativeCurrencyBalance&, nativeBalance);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetGamerCurrencyBalance, bool, bWasSuccessful, const FCurrencyBalance&, currencyBalance);

	void OnCreateAuction(bool bWasSuccessful) const;
	void OnGetProjectAuctions(FAuctionsResponse& auctionsResponse);
	void OnCreateAuctionBid(bool bWasSuccessful) const;
	void OnCreateAuctionPurchase(bool bWasSuccessful) const;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateAuction, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetProjectAuctions, const FAuctionsResponse&, auctionsResponse);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateAuctionBid, bool, bWasSuccessful);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateAuctionPurchase, bool, bWasSuccessful);

public:

	inline static UNeftaToolbox* Instance;
	
	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox")
	static UNeftaToolbox* NeftaToolboxGetInstance();

	virtual void BeginDestroy() override;
	
	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox")
	FNeftaUser& GetUser() const;
	

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Authorization")
	void SignUpGuestUser(const FString& username);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Authorization")
	void SignUpGamer(UPARAM(ref) FString& email, const FString& username);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Authorization")
	void RequestLoginCode(const FString& email);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Authorization")
	void LoginWithConfirmationCode(UPARAM(ref) FString& email, const FString& code);
	
	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Authorization")
	void GuestFullSignup(const FString& email);

	UPROPERTY(BlueprintAssignable)
	FOnSignUpGuestUser SignUpGuestUserCallback;
	
	UPROPERTY(BlueprintAssignable)
	FOnSignUpGamer SignUpGamerCallback;
	
	UPROPERTY(BlueprintAssignable)
	FOnRequestLoginCode RequestLoginCodeCallback;

	UPROPERTY(BlueprintAssignable)
	FOnLoginWithConfirmationCode LoginWithConfirmationCodeCallback;
	
	UPROPERTY(BlueprintAssignable)
	FOnGuestFullSignup GuestFullSignupCallback;

	
	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Assets")
	void CreateCurrencyRewardForUser(FString currencyId, double amount);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Assets")
	void CreateAssetRewardForUser(const FString& assetId);

	UPROPERTY(BlueprintAssignable)
	FOnCreateCurrencyRewardForUser CreateCurrencyRewardForUserCallback;

	UPROPERTY(BlueprintAssignable)
	FOnCreateCurrencyRewardForUser CreateAssetRewardForUserCallback;

	
	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Management")
	void GetGamerProfile();

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Management")
	void GetGamerOwnedAssets();

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Management")
	void GetGamerCryptoBalance();

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Gamer Management")
	void GetGamerCurrencyBalance(const FString& currencyId);

	UPROPERTY(BlueprintAssignable)
	FOnGetGamerProfile GetGamerProfileCallback;

	UPROPERTY(BlueprintAssignable)
	FOnGetGamerOwnedAssets GetGamerOwnedAssetsCallback;

	UPROPERTY(BlueprintAssignable)
	FOnGetGamerCryptoBalance GetGamerCryptoBalanceCallback;

	UPROPERTY(BlueprintAssignable)
	FOnGetGamerCurrencyBalance GetGamerCurrencyBalanceCallback;


	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Marketplace")
	void CreateAuction(const FString& ownershipId, double startPrice, double purchasePrice);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Marketplace")
	void GetProjectAuctions();

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Marketplace")
	void CreateAuctionBid(const FString& auctionId, double price);

	UFUNCTION(BlueprintCallable, Category = "Nefta Toolbox | Marketplace")
	void CreateAuctionPurchase(const FString& auctionId);

	UPROPERTY(BlueprintAssignable)
	FOnCreateAuction CreateAuctionCallback;

	UPROPERTY(BlueprintAssignable)
	FOnGetProjectAuctions GetProjectAuctionsCallback;

	UPROPERTY(BlueprintAssignable)
	FOnCreateAuctionBid CreateAuctionBidCallback;
	
	UPROPERTY(BlueprintAssignable)
	FOnCreateAuctionPurchase CreateAuctionPurchaseCallback;
};
