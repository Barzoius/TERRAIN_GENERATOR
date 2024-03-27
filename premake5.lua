workspace "TERRAIN_GENERATOR"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"]  = "TERRAIN_GENERATOR/vendor/GLFW/include"

include "TERRAIN_GENERATOR/vendor/GLFW"

project "TERRAIN_GENERATOR"
	location "TERRAIN_GENERATOR"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "PCHeaders.h"
	pchsource "TERRAIN_GENERATOR/src/PCHeaders.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%(IncludeDir.GLFW)"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TG_PLATFORM_WINDOWS",
			"TG_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SANDBOX")
		}

	filter "configurations:Debug" 
		defines "TG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release" 
		defines "TG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TG_DIST"
		buildoptions "/MD"
		optimize "On"


		
project "SANDBOX"
	location "SANDBOX"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"TERRAIN_GENERATOR/src"
	}

	links
	{
		"TERRAIN_GENERATOR"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TG_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "TG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release" 
		defines "TG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist" 
		defines "TG_DIST"
		buildoptions "/MD"
		optimize "On"