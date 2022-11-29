cmake_minimum_required(VERSION 3.16.0)

project(Exceptional)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE './vcpkg/scripts/buildsystems/vcpkg.cmake')

message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

add_subdirectory(src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
