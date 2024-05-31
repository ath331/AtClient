// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class ProtoBufCore : ModuleRules
{
	public ProtoBufCore( ReadOnlyTargetRules Target ) : base( Target )
	{
		Type = ModuleType.External;

		PublicSystemIncludePaths.Add( Path.Combine( ModuleDirectory, "Include" ) );
        PublicIncludePaths.Add( Path.Combine( ModuleDirectory, "Include" ) );
        PublicAdditionalLibraries.Add( Path.Combine( ModuleDirectory, "Lib", "Win64", "libprotobuf.lib" ) );

		PublicDefinitions.Add( "GOOGLE_PROTOBUF_NO_RTTI=1" );
    }
}
