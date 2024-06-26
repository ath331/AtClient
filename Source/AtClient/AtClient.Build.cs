// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AtClient : ModuleRules
{
	public AtClient( ReadOnlyTargetRules Target ) : base( Target )
	{
		// PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		// PrivatePCHHeaderFile = "pch.h";

		PublicDependencyModuleNames.AddRange( new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking", "EnhancedInput" } );

		PrivateDependencyModuleNames.AddRange( new string[] { "ProtoBufCore" } );

		PublicIncludePaths.AddRange( new string[]
		{
			"AtClient/",
			"AtClient/Packet/",
			"AtClient/Game/",
            "ProtoBufCore/",
            "ProtoBufCore/Include/"
        } );

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
