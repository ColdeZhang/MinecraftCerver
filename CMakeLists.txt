cmake_minimum_required(VERSION 3.22)
project(MinecraftCerver)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE MATH_UTIL "${CMAKE_SOURCE_DIR}/math/*.h"
        "${CMAKE_SOURCE_DIR}/math/*.cpp"
        "${CMAKE_SOURCE_DIR}/minecraft/*.h"
        "${CMAKE_SOURCE_DIR}/minecraft/*.cpp"
        "${CMAKE_SOURCE_DIR}/brigadier/*.h"
        "${CMAKE_SOURCE_DIR}/brigadier/*.cpp"
        "${CMAKE_SOURCE_DIR}/datafixers/*.h"
        "${CMAKE_SOURCE_DIR}/datafixers/*.cpp"
        "${CMAKE_SOURCE_DIR}/serialization/*.h"
        "${CMAKE_SOURCE_DIR}/serialization/*.cpp"
        "${CMAKE_SOURCE_DIR}/bridge/*.h"
        "${CMAKE_SOURCE_DIR}/bridge/*.cpp"
        "${CMAKE_SOURCE_DIR}/util/*.h"
        "${CMAKE_SOURCE_DIR}/util/*.cpp")

add_executable(MinecraftCerver main.cpp ${MATH_UTIL})
