cmake_minimum_required(VERSION 3.20)
project(AdventOfCode2025 CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings as errors
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wshadow
        -Wunused
    )
endif()

# Add external library (chrym.hpp)
include_directories(external/advent-of-code-cpp-library/include)

# Option to build specific day
set(AOC_DAY "ALL" CACHE STRING "Which day to build (1-12 or ALL)")

# Function to add a day's solution
function(add_day DAY_NUM)
    set(TARGET_NAME day${DAY_NUM})
    add_executable(${TARGET_NAME} ${DAY_NUM}/solve.cpp)
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endfunction()

# Build specific day or all days
if(AOC_DAY STREQUAL "ALL")
    message(STATUS "Building all days")
    foreach(DAY RANGE 1 12)
        add_day(${DAY})
    endforeach()
else()
    message(STATUS "Building day ${AOC_DAY}")
    add_day(${AOC_DAY})
endif()

# Build solver_all executable
file(GLOB DAY_SOURCES "*/solve.cpp")
add_executable(solver_all solver_all.cpp ${DAY_SOURCES})
set_target_properties(solver_all PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Custom target to run all solutions
add_custom_target(run_all
    COMMENT "Running all Advent of Code solutions"
)

foreach(DAY RANGE 1 12)
    add_custom_target(run_day${DAY}
        COMMAND day${DAY}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        DEPENDS day${DAY}
        COMMENT "Running Day ${DAY}"
    )
    add_dependencies(run_all run_day${DAY})
endforeach()
