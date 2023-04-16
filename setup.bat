@echo off
xcopy ".\source" ".\build\Game Engine\source" /E /I /H
copy ".\glad.c" ".\build\Game Engine"
premake5 vs2022
pause