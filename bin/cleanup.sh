#!/bin/bash

echo "Cleaning up project..."

cd ..

# Remove build directory
rm -rf build
mkdir build

# Remove lib directory
rm -rf lib

# Remove releases directory
rm -rf release

# Remove Visual Studio solution files
find . -name "*.sln" -type f -delete
find . -name "*.vcxproj" -type f -delete
find . -name "*.vcxproj.filters" -type f -delete
find . -name "*.vcxproj.user" -type f -delete

# Remove CMake generated files
rm -rf CMakeFiles
rm -f CMakeCache.txt cmake_install.cmake Makefile

# Remove x64 directory
rm -rf x64

# Remove .vs folder
rm -rf .vs

# Remove specific .dir directories
rm -rf Djomlica.dir helpers.dir tests.dir

# Remove all .dir directories (in case there are others)
find . -name "*.dir" -type d -exec rm -rf {} +

# Remove all CMakeFiles directories
find . -name "CMakeFiles" -type d -exec rm -rf {} +

cd bin

echo "Cleanup complete."