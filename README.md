# Advent of Code 2025

My personal solutions to the 2025 Advent of Code coding challenges, in C++.
(Some base code was build using AI to save on time, but all solutions were done without any AI assistance)

## Project Structure

```
advent-of-code-2025/
├── CMakeLists.txt          # Root CMake configuration
├── main.cpp                # Interactive solver (run single day or all)
├── external/
│   └── advent-of-code-cpp-library/  # chrym.hpp utility library (git submodule)
├── 1/
│   ├── solve.cpp           # Day 1 solution
│   ├── input.txt           # Your puzzle input (ignored by git)
│   └── test_input.txt      # Example input (ignored by git)
├── 2/
│   ├── solve.cpp
│   ├── input.txt
│   └── test_input.txt
...
└── 12/
    ├── solve.cpp
    ├── input.txt
    └── test_input.txt
```

## Requirements

- C++23 compatible compiler
- CMake 3.20 or higher
- Git (for cloning submodules)

## Quick Start

### Initial Setup

First time setup - initialize the submodule:

```bash
# Clone with submodules
git clone --recursive <repository-url>

# OR if already cloned, initialize submodules
git submodule update --init --recursive
```

### Build

```bash
# Create build directory and configure
mkdir build
cd build
cmake ..

# Build the solver
cmake --build .
```

This creates a single executable `aoc2025.exe` that can run any day or all days.

## Running Solutions

### Interactive Mode

Run the executable without arguments to get prompted:

```bash
.\aoc2025.exe

# Output:
# Advent of Code 2025 Solver
# Enter day (1-12 or 'all'): 5
# Enter input type ('input' or 'test'): test
```

### Command Line Mode

Pass the day number and input type as arguments:

```bash
# Run a specific day with test input
.\aoc2025.exe 5 test

# Run a specific day with real input
.\aoc2025.exe 5 input

# Run all days with test input
.\aoc2025.exe all test

# Run all days with real input
.\aoc2025.exe all input
```

Input type options:
- `test` - uses `test_input.txt`
- `input` - uses `input.txt` -- also default if no type provided

## Solution Template

Each day's `solve.cpp` file follows this structure:

```cpp
#include "chrym.hpp"
#include <iostream>

class Day1 {
private:
    std::vector<std::string> lines;

public:
    Day1(std::string_view path) {
        lines = chrym::read_lines(path, false);
    }

    std::string part1() {
        // TODO: Implement part 1 solution
        int result = 0;
        // return std::to_string(result);
        return "Not implemented";
    }

    std::string part2() {
        // TODO: Implement part 2 solution
        int result = 0;
        // return std::to_string(result);
        return "Not implemented";
    }
};
```

**Key Points:**
- Each day is a class (`Day1`, `Day2`, etc.) with `part1()` and `part2()` methods
- Both methods must return a `std::string` with the answer
- The constructor takes a file path and loads the input
- `#ifndef AOC_SOLVER_ALL` is used to prevent duplicate main() functions

## Adding Your Solution

1. Paste your puzzle input into `N/input.txt` (where N is the day number)
2. Open `N/solve.cpp` and implement the solution in `part1()` and/or `part2()`
3. Return the result as a string: `return std::to_string(result);`
4. Build and run: `.\aoc2025.exe N`

The `chrym::read_lines()` function loads the input file into a vector of strings (one per line).

## Timing and Benchmarking

All solutions are automatically benchmarked using `chrym::time_call()`. Each run displays:
- Answer for Part 1 and Part 2
- Execution time in milliseconds for each part
- Total time when running all days

## Compiler Settings

The project uses strict compiler warnings treated as errors:

- **GCC/Clang**: `-Wall -Wextra -Wpedantic -Werror -Wshadow -Wno-unused-variable`
- **MSVC**: `/W4 /WX`

## chrym.hpp Library

The project uses [chrym.hpp](https://github.com/Diogoperei29/advent-of-code-cpp-library) - a single-header utility library for Advent of Code with:

- **File I/O**: `read_lines()`, `read_file()`, `read_ints()`, etc.
- **Parsing**: `split()`, `is_digit()`, `to_int()`, etc.
- **Timing**: `time_call()` for simple benchmarking
- **Common algorithms**: Grid operations, pathfinding helpers, etc.

See the [library documentation](https://github.com/Diogoperei29/advent-of-code-cpp-library) for full API reference.

## License

This is personal code for Advent of Code challenges. Feel free to use as reference.
