@echo off
xcopy ".\source" ".\build\Game Engine\source" /E /I /H
premake5 vs2022
pause