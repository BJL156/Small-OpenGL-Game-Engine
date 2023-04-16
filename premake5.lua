workspace "Game Engine"
    configurations {"Debug", "Release", "Dist"}
    location "build"
    architecture "x64"

    includedirs {"src", "dependencies/GLFW/include", "dependencies/GLM/glm", "dependencies/GLAD/include"}
    libdirs {"dependencies/GLFW/lib-vc2015"}
    links {"glfw3.lib", "opengl32.lib"}

project "Game Engine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    location "build/Game Engine"

    files {"build/Game Engine/glad.c", "build/Game Engine/source/**.cpp", "build/Game Engine/source/**.hpp"}

    filter "configurations:Debug"
    defines {"DEBUG"}
    symbols "On"

    filter "configurations:Release"
    defines {"NDEBUG"}
    optimize "On"

    filter "configurations:Dist"
    kind "WindowedApp"
    entrypoint "mainCRTStartup"
    defines {"NDEBUG"}
    optimize "On"