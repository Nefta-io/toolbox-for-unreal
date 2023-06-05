// Copyright 2023, Nefta, All rights reserved

using UnrealBuildTool;

public class NeftaToolboxSDK : ModuleRules
{
	public NeftaToolboxSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { });
		
		PrivateIncludePaths.AddRange(new string[] { });
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "HTTP", "ImageWrapper", "Engine" });
		
		PrivateDependencyModuleNames.AddRange(new string[] {
				"CoreUObject",
				"Slate",
				"SlateCore",
				"Json",
				"JsonUtilities",
				"DeveloperSettings"
		});
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
