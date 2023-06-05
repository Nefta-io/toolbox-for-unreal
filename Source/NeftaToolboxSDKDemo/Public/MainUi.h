// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamerManagemenet/OwnedAsset.h"
#include "MainUi.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UMainUi : public UUserWidget
{
	GENERATED_BODY()
    
protected:
	
	class FNeftaToolboxSDKModule* NeftaSDK;
	
    UPROPERTY ( meta = (BindWidget))
    class UWidgetSwitcher* MainSwitcher;
    
    UPROPERTY ( meta = (BindWidget))
    class UAuthenticationPanel* AuthenticationPanel;

	UPROPERTY ( meta = (BindWidget))
	class UUserDetailsPanel* UserDetailsPanel;

	UPROPERTY ( meta = (BindWidget))
	class UAssetsPanel* AssetsPanel;
    
    UPROPERTY ( meta = (BindWidget))
    class UUserPanel* UserPanel;

	UPROPERTY ( meta = (BindWidget))
	class URewardPanel* RewardPanel;

	UPROPERTY ( meta = (BindWidget))
	class UAuctionPanel* AuctionPanel;

	UPROPERTY ( meta = (BindWidget))
	class UMarketplacePanel* MarketplacePanel;

	UPROPERTY ( meta = (BindWidget))
	class UAuctionsPanel* AuctionsPanel;

	UPROPERTY ( meta = (BindWidget))
	class UCurrenciesPanel* CurrenciesPanel;
	
    void NativeConstruct() override;

public:
	
	static UMainUi* Instance;

	void OpenUser();

	void OpenUserDetails();

	void OpenAssets();
	
	void OpenConvertGuestIntoFullUser();

	void OpenReward();

	void OpenAuction(FOwnedAsset& asset);

	void OpenCurrencies();

	void OpenMarketplace();

	void OpenAuctions();
};
