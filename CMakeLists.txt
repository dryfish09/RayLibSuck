cmake_minimum_required(VERSION 3.15)
project(BallGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

find_package(raylib 5.5 QUIET)

if(raylib_FOUND)
    message(STATUS "Using system-installed raylib")
else()
    message(STATUS "System raylib not found, fetching from GitHub...")
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
    )
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE raylib)

if(APPLE)
    target_link_libraries(game PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
        "-framework CoreGraphics"
        "-framework OpenGL"
    )
endif()

if(WIN32)
    target_link_libraries(game PRIVATE winmm)
endif()
