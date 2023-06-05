#include "NeftaToolbox.h"
#include "NeftaToolboxSDK.h"

UNeftaToolbox* UNeftaToolbox::NeftaToolboxGetInstance()
{
	if (Instance != nullptr)
	{
		return Instance;
	}
	
	Instance = NewObject<UNeftaToolbox>(GetTransientPackage(), StaticClass());

	Instance->Sdk = &FNeftaToolboxSDKModule::Get();
	Instance->Sdk->Init();
	
	return Instance;
}

void UNeftaToolbox::BeginDestroy()
{
	Super::BeginDestroy();

	Instance = nullptr;
}

FNeftaUser& UNeftaToolbox::GetUser() const
{
	FNeftaUser* user = Sdk->GetUser();
	if (user == nullptr)
	{
		user = new FNeftaUser();
		user->user_token = FString();
	}
	return *user;
}


void UNeftaToolbox::SignUpGuestUser(const FString& email)
{
	Sdk->Authorization->SignUpGuestUser(email).BindUObject(this, &UNeftaToolbox::OnSignUpGuestUser);
}

void UNeftaToolbox::OnSignUpGuestUser(FNeftaUser& user) const
{
	SignUpGuestUserCallback.Broadcast(user.IsValid(), user);
}

void UNeftaToolbox::SignUpGamer(FString& email, const FString& username)
{
	Sdk->Authorization->SignUpGamer(&email, username).BindUObject(this, &UNeftaToolbox::OnSignUpGamer);
}

void UNeftaToolbox::OnSignUpGamer(bool bWasSuccessful) const
{
	SignUpGamerCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::RequestLoginCode(const FString& email)
{
	Sdk->Authorization->RequestLoginCode(email).BindUObject(this, &UNeftaToolbox::OnRequestLoginCode);
}

void UNeftaToolbox::OnRequestLoginCode(bool bWasSuccessful) const
{
	RequestLoginCodeCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::LoginWithConfirmationCode(FString& email, const FString& code)
{
	Sdk->Authorization->LoginWithConfirmationCode(&email, code).BindUObject(this, &UNeftaToolbox::OnLoginWithConfirmationCode);
}

void UNeftaToolbox::OnLoginWithConfirmationCode(FNeftaUser& user) const
{
	LoginWithConfirmationCodeCallback.Broadcast(user.IsValid(), user);
}

void UNeftaToolbox::GuestFullSignup(const FString& email)
{
	 Sdk->Authorization->GuestFullSignup(email).BindUObject(this, &UNeftaToolbox::OnGuestFullSignup);
}

void UNeftaToolbox::OnGuestFullSignup(bool bWasSuccessful) const
{
	GuestFullSignupCallback.Broadcast(bWasSuccessful, *Instance->Sdk->GetUser());
}


void UNeftaToolbox::CreateCurrencyRewardForUser(FString currencyId, double amount)
{
	Sdk->GamerAssets->CreateCurrencyRewardForUser(currencyId, amount).BindUObject(this, &UNeftaToolbox::OnCreateCurrencyRewardForUser);
}

void UNeftaToolbox::OnCreateCurrencyRewardForUser(bool bWasSuccessful) const
{
	CreateCurrencyRewardForUserCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::CreateAssetRewardForUser(const FString& assetId)
{
	Sdk->GamerAssets->CreateAssetRewardForUser(assetId).BindUObject(this, &UNeftaToolbox::OnCreateAssetRewardForUser);
}

void UNeftaToolbox::OnCreateAssetRewardForUser(bool bWasSuccessful) const
{
	CreateAssetRewardForUserCallback.Broadcast(bWasSuccessful);
}


void UNeftaToolbox::GetGamerProfile()
{
	Sdk->GamerManagement->GetGamerProfile().BindUObject(this, &UNeftaToolbox::OnGetGamerProfile);
}

void UNeftaToolbox::OnGetGamerProfile(bool bWasSuccessful) const
{
	GetGamerProfileCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::GetGamerOwnedAssets()
{
	Sdk->GamerManagement->GetGamerOwnedAssets().BindUObject(this, &UNeftaToolbox::OnGetGamerOwnedAssets);
}

void UNeftaToolbox::OnGetGamerOwnedAssets(FOwnedAssetsResponse& ownedAssetsResponse)
{
	GetGamerOwnedAssetsCallback.Broadcast(ownedAssetsResponse);
}

void UNeftaToolbox::GetGamerCryptoBalance()
{
	Sdk->GamerManagement->GetGamerCryptoBalance().BindUObject(this, &UNeftaToolbox::OnGetGamerCryptoBalance);
}

void UNeftaToolbox::OnGetGamerCryptoBalance(bool bWasSuccessful, FNativeCurrencyBalance& balance) const
{
	GetGamerCryptoBalanceCallback.Broadcast(bWasSuccessful, balance);
}

void UNeftaToolbox::GetGamerCurrencyBalance(const FString& currencyId)
{
	Sdk->GamerManagement->GetGamerCurrencyBalance(currencyId).BindUObject(this, &UNeftaToolbox::OnGetGamerCurrencyBalance);
}

void UNeftaToolbox::OnGetGamerCurrencyBalance(bool bWasSuccessful, FCurrencyBalance& balance) const
{
	if (GetGamerCurrencyBalanceCallback.IsBound())
	{
		GetGamerCurrencyBalanceCallback.Broadcast(bWasSuccessful, balance);
	}
}


void UNeftaToolbox::CreateAuction(const FString& ownershipId, double startPrice, double purchasePrice)
{
	Sdk->Marketplace->CreateAuction(ownershipId, startPrice, purchasePrice)
	.BindUObject(this, &UNeftaToolbox::OnCreateAuction);
}

void UNeftaToolbox::OnCreateAuction(bool bWasSuccessful) const
{
	CreateAuctionCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::GetProjectAuctions()
{
	Sdk->Marketplace->GetProjectAuctions()
	.BindUObject(this, &UNeftaToolbox::OnGetProjectAuctions);
}

void UNeftaToolbox::OnGetProjectAuctions(FAuctionsResponse& auctionsResponse)
{
	GetProjectAuctionsCallback.Broadcast(auctionsResponse);
}

void UNeftaToolbox::CreateAuctionBid(const FString& auctionId, double price)
{
	Sdk->Marketplace->CreateAuctionBid(auctionId, price)
	.BindUObject(this, &UNeftaToolbox::OnCreateAuctionBid);
}

void UNeftaToolbox::OnCreateAuctionBid(bool bWasSuccessful) const
{
	CreateAuctionBidCallback.Broadcast(bWasSuccessful);
}

void UNeftaToolbox::CreateAuctionPurchase(const FString& auctionId)
{
	Sdk->Marketplace->CreateAuctionPurchase(auctionId)
	.BindUObject(this, &UNeftaToolbox::OnCreateAuctionPurchase);
}

void UNeftaToolbox::OnCreateAuctionPurchase(bool bWasSuccessful) const
{
	CreateAuctionPurchaseCallback.Broadcast(bWasSuccessful);
}
