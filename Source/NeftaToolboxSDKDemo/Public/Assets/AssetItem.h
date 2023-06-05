// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamerManagemenet/OwnedAsset.h"
#include "AssetItem.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAssetItem : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UImage* Image;
	
	UPROPERTY ( meta = (BindWidget))
	class UButton* CreateAuction;
	
	UFUNCTION()
	void OnCreateAuction();

	FOwnedAsset* Asset;

	UFUNCTION()
	void OnAssetLoaded(bool bWasSuccessful);

	void NativeConstruct() override;

public:
	UFUNCTION()
	void Set(FOwnedAsset& asset);
	
};
