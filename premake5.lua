workspace "DreamEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "DreamEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "DreamEngine/vendor/Glad/include"

include "DreamEngine/vendor/GLFW"
include "DreamEngine/vendor/Glad"

project "DreamEngine"
	location "DreamEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	pchheader "depch.h"
	pchsource "DreamEngine/src/depch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"DE_PLATFORM_WINDOWS",
			"DE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions { "/utf-8" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DE_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"DreamEngine/vendor/spdlog/include",
		"DreamEngine/src"
	}

	links
	{
		"DreamEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"DE_PLATFORM_WINDOWS"
		}

		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "DE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DE_DIST"
		buildoptions "/MD"
		optimize "On"