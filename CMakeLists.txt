cmake_minimum_required(VERSION 3.20)
project(AdventOfCode2025 CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings as errors
if(MSVC)
    add_compile_options(/W4 /WX /wd4189)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wshadow
        -Wno-unused-variable
    )
endif()

# Add external library (chrym.hpp)
include_directories(external/advent-of-code-cpp-library/include)

# Build the main solver executable
add_executable(aoc2025 main.cpp)
