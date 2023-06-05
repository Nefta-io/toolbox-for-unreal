#pragma once
#include "NeftaUser.h"
#include "Interfaces/IHttpRequest.h"

class ToolboxCore
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateRequest(const FString& url) const;
	
public:
	const FString BaseUrl = "https://api.Nefta.io/v2.0";

	const FString SlotName = "NeftaDemoSession";
	const int32 SlotIndex = 0;

	FNeftaUser* NeftaUser;
	
	const FString MarketplaceId;

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateGetRequest(const FString& url) const;
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreatePostRequest(const FString& url, TSharedPtr<FJsonObject> body) const;

	ToolboxCore(const FString& marketplaceId);

	void SetUser(FNeftaUser* neftaUser);

	FNeftaUser* GetUser() const;

	void SaveSession() const;
};
