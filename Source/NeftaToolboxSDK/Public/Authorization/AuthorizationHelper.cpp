#include "AuthorizationHelper.h"
#include "NeftaToolboxSDK.h"
#include "ConfirmGamerAccountWithEmailCode.h"
#include "ConverGuestToFullUserRequest.h"
#include "JsonObjectConverter.h"
#include "NeftaUser.h"
#include "RequestLoginCodeRequest.h"
#include "SignUpGamerRequest.h"
#include "SignupGuestUserRequest.h"
#include "Interfaces/IHttpResponse.h"

AuthorizationHelper::AuthorizationHelper(ToolboxCore* core)
{
	Core = core;
}

AuthorizationHelper::OnSignUpGuestUserDelegate& AuthorizationHelper::SignUpGuestUser(const FString& username)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("SignUpGuestUser"));

	FSignupGuestUserRequest requestBody;
	requestBody.public_project_id = Core->MarketplaceId;
	requestBody.username = username;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);

	const auto request = Core->CreatePostRequest("/gamer/signup", requestObject);
	
	request->OnProcessRequestComplete().BindRaw(this, &AuthorizationHelper::OnSignUpGuestUser);
	request->ProcessRequest();

	return OnSignUpGuestUserCallback;
}

void AuthorizationHelper::OnSignUpGuestUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FNeftaUser* user = new FNeftaUser;
	const int32 responseCode = response->GetResponseCode();
    const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnSignUpGuestUser response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300)
	{
		FJsonObjectConverter::JsonObjectStringToUStruct<FNeftaUser>(responseBody, user, 0, 0);
		if (user->IsValid())
		{
			Core->SetUser(user);
			Core->SaveSession();
		}
	}

	OnSignUpGuestUserCallback.Execute(*user);
}

AuthorizationHelper::OnSignUpGamerDelegate& AuthorizationHelper::SignUpGamer(FString* email, const FString& username)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("SignUpGamer"));

	Email = email;
	
	FSignUpGamerRequest requestBody;
	requestBody.public_project_id = Core->MarketplaceId;
	requestBody.email = *email;
	requestBody.username = username;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);

	const auto request = Core->CreatePostRequest("/gamer/full-signup", requestObject);
	    
	request->OnProcessRequestComplete().BindRaw(this, &AuthorizationHelper::OnSignUpGamer);
	request->ProcessRequest();

	return OnSignUpGamerCallback;
}

void AuthorizationHelper::OnSignUpGamer(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnSignUpGamer response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
	OnSignUpGamerCallback.Execute(bWasSuccessful);
}

AuthorizationHelper::OnRequestLoginCodeDelegate& AuthorizationHelper::RequestLoginCode(const FString& email)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("RequestLoginCode"));

	FRequestLoginCodeRequest requestBody;
	requestBody.email = email;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);
	
	const auto request = Core->CreatePostRequest("/gamer/confirm/resend", requestObject);
	    
	request->OnProcessRequestComplete().BindRaw(this, &AuthorizationHelper::OnRequestLoginCode);
	request->ProcessRequest();

	return OnRequestLoginCodeCallback;
}

void AuthorizationHelper::OnRequestLoginCode(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnRequestLoginCode response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
	OnRequestLoginCodeCallback.Execute(bWasSuccessful);
}

AuthorizationHelper::OnLoginWithConfirmationCodeDelegate& AuthorizationHelper::LoginWithConfirmationCode(FString* email, const FString& code)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("LoginWithConfirmationCode"));

	Email = email;
	
	FConfirmGamerAccountWithEmailCode requestBody;
	requestBody.code = code;
	requestBody.email = *email;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);

	const auto request = Core->CreatePostRequest("gamer/login/code", requestObject);
	
	request->OnProcessRequestComplete().BindRaw(this, &AuthorizationHelper::OnLoginWithConfirmationCode);
	request->ProcessRequest();

	return OnLoginWithConfirmationCodeCallback;
}

void AuthorizationHelper::OnLoginWithConfirmationCode(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	FNeftaUser* user = new FNeftaUser();
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnLoginWithConfirmationCode response %d %s"), responseCode, *FString(responseBody));
	if (200 <= responseCode && responseCode < 300)
	{
		FJsonObjectConverter::JsonObjectStringToUStruct<FNeftaUser>(responseBody, user, 0, 0);
		if (user->IsValid())
		{
			user->email = *Email;
			Core->SetUser(user);
			Core->SaveSession();
		}
	}
	
	OnLoginWithConfirmationCodeCallback.Execute(*user);
}

AuthorizationHelper::OnGuestFullSignupDelegate& AuthorizationHelper::GuestFullSignup(const FString& email)
{
	UE_LOG(LogNeftaToolbox, Log, TEXT("GuestFullSignup %s"), *FString(email));

	FConvertGuestToFullUserRequest requestBody;
	requestBody.email = email;
	const TSharedPtr<FJsonObject> requestObject = FJsonObjectConverter::UStructToJsonObject(requestBody);

	const auto request = Core->CreatePostRequest("/gamer/confirm", requestObject);
	    
	request->OnProcessRequestComplete().BindRaw(this, &AuthorizationHelper::OnGuestFullSignup);
	request->ProcessRequest();

	return OnGuestFullSignupCallback;
}

void AuthorizationHelper::OnGuestFullSignup(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const
{
	const int32 responseCode = response->GetResponseCode();
	const FString responseBody = response->GetContentAsString();
	UE_LOG(LogNeftaToolbox, Log, TEXT("OnGuestFullSignup response %d %s"), responseCode, *FString(responseBody));
	bWasSuccessful = 200 <= responseCode && responseCode < 300;
    OnGuestFullSignupCallback.Execute(bWasSuccessful);
}
