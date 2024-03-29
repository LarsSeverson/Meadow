workspace "Meadow"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Meadow/vendor/GLFW/include"
IncludeDir["glad"] = "Meadow/vendor/glad/include"
IncludeDir["imgui"] = "Meadow/vendor/imgui"
IncludeDir["stb_image"] = "Meadow/vendor/stb_image"
IncludeDir["glm"] = "Meadow/vendor/glm"

include "Meadow/vendor/GLFW"
include "Meadow/vendor/glad"
include "Meadow/vendor/imgui"

project "Meadow"
    location "Meadow"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mdpch.h"
    pchsource "Meadow/src/mdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.glm}"
    }

    links {
        "GLFW", 
        "glad",
        "opengl32.lib",
        "imgui"
    }


    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MD_PLATFORM_WINDOWS",
            "MD_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MD_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MD_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "MD_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
        
        includedirs
        {
            "Meadow/src",
            "Meadow/vendor/spdlog/include",
            "Meadow/vendor",
            "%{IncludeDir.glm}"
        }

        links
        {
            "Meadow"
        }
    
        filter "system:windows"
            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "MD_PLATFORM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "MD_DEBUG"
            runtime "Debug"
            symbols "on"
    
        filter "configurations:Release"
            defines "MD_RELEASE"
            runtime "Release"
            optimize "on"
    
        filter "configurations:Dist"
            defines "MD_DIST"
            runtime "Release"
            optimize "on"
    