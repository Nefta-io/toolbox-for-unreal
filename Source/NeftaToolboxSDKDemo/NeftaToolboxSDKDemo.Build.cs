// Copyright 2023, Nefta, All rights reserved

using UnrealBuildTool;

public class NeftaToolboxSDKDemo : ModuleRules
{
	public NeftaToolboxSDKDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { });
		
		PrivateIncludePaths.AddRange(new string[] { });
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"NeftaToolboxSDK"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore"
		});
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
