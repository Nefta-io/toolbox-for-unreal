#pragma once

#include "ToolboxConfiguration.generated.h"

UCLASS(Config=Game, defaultconfig, meta = (DisplayName="Nefta Toolbox SDK"))
class NEFTATOOLBOXSDK_API UToolboxConfiguration : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Nefta Toolbox SDK | Configuration")
	FString MarketplaceId;
};
