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

project "Meadow"
    location "Meadow"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }


    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MD_PLATFORM_WINDOWS",
            "MD_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MD_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MD_DIST"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "Meadow/src"
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
            symbols "On"
    
        filter "configurations:Release"
            defines "MD_RELEASE"
            optimize "On"
    
        filter "configurations:Dist"
            defines "MD_DIST"
            optimize "On"
    