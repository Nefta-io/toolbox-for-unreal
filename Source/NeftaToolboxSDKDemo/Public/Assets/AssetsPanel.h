// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamerManagemenet/OwnedAssetsResponse.h"
#include "AssetsPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API UAssetsPanel : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY ( meta = (BindWidget))
	class UScrollBox* AssetList;
	
	UPROPERTY ( meta = (BindWidget))
	class UButton* Close;

	void NativeConstruct() override;

	UFUNCTION()
	void OnUpdateAssets(FOwnedAssetsResponse& assetsResponse);
	
	UFUNCTION()
	void OnClose();

public:
	UPROPERTY (Category="Prefab", BlueprintReadWrite, meta = (BindWidgetOptional))
	TSubclassOf<class UAssetItem> AssetItemPrefab;
	
	UFUNCTION()
	void UpdateAssets();
};
