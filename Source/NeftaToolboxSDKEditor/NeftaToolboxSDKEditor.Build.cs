// Copyright 2023, Nefta, All rights reserved

using UnrealBuildTool;

public class NeftaToolboxSDKEditor : ModuleRules
{
	public NeftaToolboxSDKEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { });
		
		PrivateIncludePaths.AddRange(new string[] { });
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"Engine",
			"CoreUObject",
			"InputCore",
			"LevelEditor",
			"Slate",
			"SlateCore",
			"EditorStyle",
			"AssetTools",
			"EditorWidgets",
			"UnrealEd",
			"NeftaToolboxSDK"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"Engine",
			"CoreUObject",
			"InputCore",
			"LevelEditor",
			"Slate",
			"SlateCore",
			"EditorStyle",
			"AssetTools",
			"EditorWidgets",
			"UnrealEd",
			"NeftaToolboxSDK"
		});
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
