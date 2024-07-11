cmake_minimum_required(VERSION 3.12)
project(Djomlica)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory for built targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Define SDL2 paths
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/vendors/SDL2")
set(SDL2_INCLUDE_DIRS "${SDL2_DIR}/include")
set(SDL2_LIBRARY_DIR "${SDL2_DIR}/lib/x64")
set(SDL2_LIBRARIES "${SDL2_LIBRARY_DIR}/SDL2.lib;${SDL2_LIBRARY_DIR}/SDL2main.lib")

# Add ImGui
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/vendors/imgui")

# Helper function to add a library or executable
function(add_project_target TARGET_NAME SOURCE_DIR TYPE)
    file(GLOB_RECURSE SOURCE_FILES
        "${SOURCE_DIR}/*.cpp"
        "${SOURCE_DIR}/*.h"
    )
    
    if(${TYPE} STREQUAL "EXECUTABLE")
        add_executable(${TARGET_NAME} ${SOURCE_FILES})
    else()
        add_library(${TARGET_NAME} ${SOURCE_FILES})
    endif()
    
    target_include_directories(${TARGET_NAME} PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${IMGUI_DIR}
        ${CMAKE_SOURCE_DIR}/helpers
    )
    
    if(${TYPE} STREQUAL "EXECUTABLE")
        target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARIES})
    else()
        target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARY_DIR}/SDL2.lib)
    endif()
endfunction()

# Add the helpers library
add_project_target(helpers_lib ${CMAKE_SOURCE_DIR}/helpers "LIBRARY")

# Add the main project
add_project_target(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/project "EXECUTABLE")

# Add the test project
add_project_target(tests ${CMAKE_SOURCE_DIR}/test "EXECUTABLE")

# Set the startup project to the main project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})