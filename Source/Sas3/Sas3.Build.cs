// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Sas3 : ModuleRules
{
	public Sas3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "SourceControl" });
	}
}
