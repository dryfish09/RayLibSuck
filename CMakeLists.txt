cmake_minimum_required(VERSION 3.15)
project(BallGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If no build type set, use Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Find raylib
find_package(raylib 5.5 REQUIRED)

add_executable(game main.cpp)

# Link raylib
target_link_libraries(game PRIVATE raylib)

# On Linux, also need these
if(UNIX AND NOT APPLE)
    target_link_libraries(game PRIVATE GL m pthread dl rt X11)
endif()
