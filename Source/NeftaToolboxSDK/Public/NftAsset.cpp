#include "NftAsset.h"

#include <cstring>

#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "IImageWrapperModule.h"
#include "IImageWrapper.h"
#include "Engine/Texture2D.h"

TMap<FString, UTexture2D*> UNftAsset::CachedTextures;

UNftAsset::UNftAsset()
{
	LoadedTexture = nullptr;
}

void UNftAsset::Init()
{
	if (CachedTextures.Contains(image))
	{
		LoadedTexture = *CachedTextures.Find(image);
	}
}

void UNftAsset::LoadImage()
{
	const FString imageUrl = EscapeImageUrl(image);
	UE_LOG(LogTemp, Log, TEXT("LoadImage %s"), *imageUrl);
	
	FHttpModule* Http = &FHttpModule::Get();
	const TSharedRef<IHttpRequest> httpRequest = Http->CreateRequest();

	httpRequest->SetVerb(TEXT("GET"));
	httpRequest->SetURL(imageUrl);
	httpRequest->OnProcessRequestComplete().BindUObject(this, &UNftAsset::OnLoadImage);
	httpRequest->ProcessRequest();
}

void UNftAsset::OnLoadImage(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	LoadedTexture = nullptr;
	const int32 responseCode = response->GetResponseCode();
	UE_LOG(LogTemp, Log, TEXT("OnLoadImage response %d"), responseCode);
	if (200 <= responseCode && responseCode < 400)
	{
		IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

		const TArray<uint8>& content = response->GetContent();
		const EImageFormat format = imageWrapperModule.DetectImageFormat(content.GetData(), content.Num());
		const TSharedPtr<IImageWrapper> imageWrapper = imageWrapperModule.CreateImageWrapper(format);
		if (imageWrapper.IsValid() && imageWrapper->SetCompressed(content.GetData(), content.Num()))
		{
			TArray<uint8> unCompressedContent;
			if (imageWrapper->GetRaw(ERGBFormat::BGRA, 8, unCompressedContent))
			{
				LoadedTexture = UTexture2D::CreateTransient(imageWrapper->GetWidth(), imageWrapper->GetHeight(), PF_B8G8R8A8);

				if (LoadedTexture != nullptr)
				{
					auto textureData = LoadedTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
					FMemory::Memcpy(textureData, unCompressedContent.GetData(), unCompressedContent.Num());
					LoadedTexture->GetPlatformData()->Mips[0].BulkData.Unlock();
					LoadedTexture->UpdateResource();

					CachedTextures.Add(image, LoadedTexture);
				}
			}
		}
	}

	if (OnLoadImageCallback.IsBound())
	{
		OnLoadImageCallback.Broadcast(this);
	}
}

FString UNftAsset::EscapeImageUrl(const FStringView url) const
{
	const FTCHARToUTF8 converter(url.GetData(), url.Len());
	const UTF8CHAR* UTF8Data = (UTF8CHAR*) converter.Get();
	FString encodedString = TEXT("");

	TCHAR Buffer[2] = { 0, 0 };
	const char allowedChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~:/#";
	const int allowedCharLength = strlen(allowedChars);

	for (int32 ByteIdx = 0, Length = converter.Length(); ByteIdx < Length; ++ByteIdx)
	{
		const UTF8CHAR byteToEncode = UTF8Data[ByteIdx];

		bool isValidCharacter = false;
		for (int i = 0; i < allowedCharLength; i++)
		{
			if (allowedChars[i] == byteToEncode)
			{
				isValidCharacter = true;
				break;
			}
		}
		
		if (isValidCharacter)
		{
			Buffer[0] = byteToEncode;
			FString TmpString = Buffer;
			encodedString += TmpString;
		}
		else if (byteToEncode != '\0')
		{
			encodedString += TEXT("%");
			encodedString += FString::Printf(TEXT("%.2X"), byteToEncode);
		}
	}
	return encodedString;
}

