#include "ToolboxCore.h"
#include "HttpModule.h"
#include "NeftaSession.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/JsonSerializer.h"

ToolboxCore::ToolboxCore(const FString& marketplaceId) : MarketplaceId(marketplaceId)
{
	NeftaUser = nullptr;

	const UNeftaSession* session = Cast<UNeftaSession>(UGameplayStatics::LoadGameFromSlot(SlotName, SlotIndex));
	if (session != nullptr && session->User.IsValid())
	{
		NeftaUser = new FNeftaUser(session->User);
		UE_LOG(LogNeftaToolbox, Log, TEXT("Loaded user with token: %s"), *FString(NeftaUser->user_token));
	}
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> ToolboxCore::CreateRequest(const FString& url) const
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = httpModule.CreateRequest();
	request->SetVerb("GET");
	if (NeftaUser != nullptr && NeftaUser->IsValid())
	{
		request->SetHeader("Authorization", "Bearer " + NeftaUser->user_token);
	}
	request->SetURL(BaseUrl + url);

	return request;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> ToolboxCore::CreateGetRequest(const FString& url) const
{
	const auto request = CreateRequest(url);
	request->SetVerb("GET");
	request->SetURL(BaseUrl + url);
	return request;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> ToolboxCore::CreatePostRequest(const FString& url, TSharedPtr<FJsonObject> body) const
{
	const auto request = CreateRequest(url);
	request->SetVerb("POST");
	request->SetHeader("Content-Type", "application/json");

	if (body != nullptr)
	{
		FString requestString;
		const TSharedRef<TJsonWriter<> > writer = TJsonWriterFactory<>::Create(&requestString);
		FJsonSerializer::Serialize(body.ToSharedRef(), writer);
		request->SetContentAsString(requestString);
	}
	
	return request;
}

void ToolboxCore::SetUser(FNeftaUser* neftaUser)
{
	NeftaUser = neftaUser;
	SaveSession();
}

FNeftaUser* ToolboxCore::GetUser() const
{
	return NeftaUser;
}

void ToolboxCore::SaveSession() const
{
	UNeftaSession* session = Cast<UNeftaSession>(UGameplayStatics::CreateSaveGameObject(UNeftaSession::StaticClass()));
	session->User = *NeftaUser;
    
	UGameplayStatics::SaveGameToSlot(session, SlotName, SlotIndex);

	UE_LOG(LogNeftaToolbox, Log, TEXT("Saving user with token: %s"), *FString(NeftaUser->user_token));
}
