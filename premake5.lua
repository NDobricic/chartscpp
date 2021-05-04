workspace "ChartsCPP"

	configurations
	{
		"Debug",
		"Release"
	}
	
	 platforms
	 {
		"x86",
		"x86_64"
	 }
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ChartsCore"
	location "ChartsCore"
	kind "StaticLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/res/**"
	}
	
	filter "configurations:Debug"
		symbols "On"
		
	filter "configurations:Release"
		optimize "On"
	
	filter "system:Windows"
		systemversion "latest"

		
		
project "ChartsSFML"
	location "ChartsSFML"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/res/**"
	}

	includedirs
	{
		"deps/SFML/include",
		"ChartsCore/src"
	}
	
	libdirs
	{
		"deps/SFML/lib"
	}
	
	links
	{
		"opengl32",
		"freetype",
		"winmm",
		"gdi32",
		"ChartsCore"
	}
	
	defines
	{
		"SFML_STATIC"
	}
	
	filter "system:Windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		links
		{
			"sfml-system-s-d", 
			"sfml-window-s-d", 
			"sfml-graphics-s-d"
		}
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
		links
		{
			"sfml-system-s", 
			"sfml-window-s", 
			"sfml-graphics-s"
		}