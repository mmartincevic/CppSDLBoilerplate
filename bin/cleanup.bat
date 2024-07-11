@echo off
echo Cleaning up project...

rem Remove build directory
if exist build rmdir /s /q build
mkdir build

rem Remove lib directory
if exist lib rmdir /s /q lib

rem Remove releases directory
if exist release rmdir /s /q release


rem Remove Visual Studio solution files
del /s /q *.sln
del /s /q *.vcxproj
del /s /q *.vcxproj.filters
del /s /q *.vcxproj.user

rem Remove CMake generated files
if exist CMakeFiles rmdir /s /q CMakeFiles
if exist CMakeCache.txt del CMakeCache.txt
if exist cmake_install.cmake del cmake_install.cmake
if exist Makefile del Makefile

rem Remove x64 directory
if exist x64 rmdir /s /q x64

rem Remove .vs folder
if exist .vs rmdir /s /q .vs

rem Remove specific .dir directories
if exist Djomlica.dir rmdir /s /q Djomlica.dir
if exist helpers.dir rmdir /s /q helpers.dir
if exist tests.dir rmdir /s /q tests.dir

rem Remove all .dir directories (in case there are others)
for /d /r %%d in (*.dir) do @if exist "%%d" rd /s /q "%%d"

rem Remove all CMakeFiles directories
for /d /r %%d in (CMakeFiles) do @if exist "%%d" rd /s /q "%%d"

echo Cleanup complete.