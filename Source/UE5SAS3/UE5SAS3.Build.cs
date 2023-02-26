// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5SAS3 : ModuleRules
{
	public UE5SAS3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
