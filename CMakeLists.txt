cmake_minimum_required(VERSION 3.22)
project(MinecraftCerver)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE MATH_UTIL "${CMAKE_SOURCE_DIR}/math/*h"
                            "${CMAKE_SOURCE_DIR}/math/*cpp"
                            "${CMAKE_SOURCE_DIR}/minecraft/*h"
                            "${CMAKE_SOURCE_DIR}/minecraft/*cpp")

add_executable(MinecraftCerver main.cpp ${MATH_UTIL})
