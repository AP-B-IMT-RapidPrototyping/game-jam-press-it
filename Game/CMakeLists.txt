cmake_minimum_required(VERSION 4.1)
project(Game)
include(FetchContent)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

add_executable(Game Main.cpp)
target_link_libraries(Game raylib)