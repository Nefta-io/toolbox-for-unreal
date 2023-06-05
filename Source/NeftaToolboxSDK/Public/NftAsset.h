#pragma once
#include "Characteristics.h"
#include "Interfaces/IHttpRequest.h"

#include "NftAsset.generated.h"

UCLASS(Blueprintable)
class NEFTATOOLBOXSDK_API UNftAsset : public UObject
{
	GENERATED_BODY()

	static TMap<FString, UTexture2D*> CachedTextures;
	
	FString EscapeImageUrl(FStringView url) const;

	void OnLoadImage(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadImageDelegate, bool, bWasSuccessful);

	UFUNCTION(BlueprintCallable, Category = "Nefta NFT")
	void Init();
	
	UPROPERTY(BlueprintAssignable, Category = "Nefta NFT")
	FOnLoadImageDelegate OnLoadImageCallback;
	
	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FString asset_id;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FString asset_name;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FString image;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FString assetSprite;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FString asset_type;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	int32 available_instances = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	int32 instances = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	TMap<FString, FString> traits;

	UPROPERTY(BlueprintReadOnly, Category = "Nefta NFT")
	FCharacteristics asset_characteristics;

	UFUNCTION(BlueprintCallable, Category = "Nefta NFT")
	void LoadImage();

	UPROPERTY(BlueprintReadWrite, Category = "Nefta NFT")
	UTexture2D* LoadedTexture;
	
	UNftAsset();
};
