cmake_minimum_required(VERSION 3.15)
project(BallGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(raylib 5.5 REQUIRED)

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(game PRIVATE GL m pthread dl rt X11)
endif()

if(APPLE)
    target_link_libraries(game PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
    )
endif()
