workspace "ZakiForge"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ZakiForge"
	location "ZakiForge"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"ZF_PLATFORM_WINDOWS",
			"ZF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")

		}

	buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "ZF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZF_DIST"
		optimize "On"





project "Sandbox"
	location "ZakiForge"
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
		"ZakiForge/vendor/spdlog/include",
		"ZakiForge/src"
	}

	links
	{
		"ZakiForge"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"ZF_PLATFORM_WINDOWS"
		}

	buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "ZF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZF_DIST"
		optimize "On"