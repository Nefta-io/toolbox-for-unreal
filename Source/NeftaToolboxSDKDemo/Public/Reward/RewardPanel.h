// Copyright 2023, Nefta, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RewardPanel.generated.h"

UCLASS()
class NEFTATOOLBOXSDKDEMO_API URewardPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY ( meta = (BindWidget))
	class UEditableText* AssetId;
    
	UPROPERTY ( meta = (BindWidget))
	class UButton* Reward;

	UPROPERTY ( meta = (BindWidget))
	UButton* Close;

	UFUNCTION()
	void OnReward();

	UFUNCTION()
	void OnRewardComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnClose();

	void NativeConstruct() override;
	
};
