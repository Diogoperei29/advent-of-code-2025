cmake_minimum_required(VERSION 3.20)
project(Day10 CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings as errors
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(
        -Wall -Wextra -Wpedantic -Werror
        -Wshadow -Wunused
    )
endif()

# Google Benchmark
include(FetchContent)
set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_INSTALL OFF)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
FetchContent_MakeAvailable(benchmark)

add_executable(day10 solve.cpp)
target_link_libraries(day10 PRIVATE benchmark::benchmark)
