#pragma once
#include "NeftaUser.h"
#include "ToolboxCore.h"
#include "Interfaces/IHttpRequest.h"

class NEFTATOOLBOXSDK_API AuthorizationHelper
{
	ToolboxCore* Core;
	
	DECLARE_DELEGATE_OneParam(OnSignUpGuestUserDelegate, FNeftaUser&);
	OnSignUpGuestUserDelegate OnSignUpGuestUserCallback;
	void OnSignUpGuestUser(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_OneParam(OnSignUpGamerDelegate, bool);
	OnSignUpGamerDelegate OnSignUpGamerCallback;
	void OnSignUpGamer(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_OneParam(OnRequestLoginCodeDelegate, bool);
	OnRequestLoginCodeDelegate OnRequestLoginCodeCallback;
	void OnRequestLoginCode(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;
	
	DECLARE_DELEGATE_OneParam(OnLoginWithConfirmationCodeDelegate, FNeftaUser&);
	OnLoginWithConfirmationCodeDelegate OnLoginWithConfirmationCodeCallback;
	void OnLoginWithConfirmationCode(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	DECLARE_DELEGATE_OneParam(OnGuestFullSignupDelegate, bool);
	OnGuestFullSignupDelegate OnGuestFullSignupCallback;
	void OnGuestFullSignup(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) const;

	FString* Email;

public:
	AuthorizationHelper(ToolboxCore* core);
	
	OnSignUpGuestUserDelegate& SignUpGuestUser(const FString& username);

	OnSignUpGamerDelegate& SignUpGamer(FString* email, const FString& username);

	OnRequestLoginCodeDelegate& RequestLoginCode(const FString& email);

	OnLoginWithConfirmationCodeDelegate& LoginWithConfirmationCode(FString* email, const FString& code);

	OnGuestFullSignupDelegate& GuestFullSignup(const FString& email);
};
