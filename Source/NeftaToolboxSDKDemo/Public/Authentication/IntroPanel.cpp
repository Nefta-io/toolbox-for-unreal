// Copyright 2023, Nefta, All rights reserved


#include "IntroPanel.h"

#include <Components/Button.h>
#include "AuthenticationPanel.h"

void UIntroPanel::Init(UAuthenticationPanel* authenticationPanel)
{
	AuthenticationPanel = authenticationPanel;

	GoogleSignUp->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpWithGoogle);
	AppleSignUp->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpWithApple);
	FacebookSignUp->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpWithFacebook);
	TwitchSignUp->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpWithTwitch);
	
	SignUpAsGuest->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpAsGuest);
	SignUpAsFullUser->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnSignUpAsFullUser);
	Login->OnClicked.AddUniqueDynamic(this, &UIntroPanel::OnLogin);
}

void UIntroPanel::OnSignUpWithGoogle()
{
	AuthenticationPanel->OpenOAuth();
}

void UIntroPanel::OnSignUpWithApple()
{
	AuthenticationPanel->OpenOAuth();
}

void UIntroPanel::OnSignUpWithFacebook()
{
	AuthenticationPanel->OpenOAuth();
}

void UIntroPanel::OnSignUpWithTwitch()
{
	AuthenticationPanel->OpenOAuth();
}

void UIntroPanel::OnSignUpAsGuest()
{
	AuthenticationPanel->OpenGuest();
}

void UIntroPanel::OnSignUpAsFullUser()
{
	AuthenticationPanel->OpenFullUser();
}

void UIntroPanel::OnLogin()
{
	AuthenticationPanel->OpenLogin();
}