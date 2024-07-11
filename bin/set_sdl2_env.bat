@echo off
REM Get the directory of the current script
set "SDL2_DIR=%~dp0vendors\SDL2"

REM Add SDL2 include directory to INCLUDE
setx INCLUDE "%INCLUDE%;%SDL2_DIR%\include"

REM Add SDL2 library directories to LIB
setx LIB "%LIB%;%SDL2_DIR%\lib\x64"

REM Add SDL2 binary directory to PATH
setx PATH "%PATH%;%SDL2_DIR%\bin"

echo SDL2 environment variables have been set.
pause