# Advent of Code 2025

My personal solutions to the 2025 Advent of Code coding challenges, in C++.

## Project Structure

```
advent-of-code-2025/
├── CMakeLists.txt          # Root CMake configuration
├── solver_all.cpp          # Run all days at once
├── external/
│   └── advent-of-code-cpp-library/  # chrym.hpp utility library (git submodule)
├── 1/
│   ├── CMakeLists.txt      # Day 1 CMake (can be used standalone)
│   ├── solve.cpp           # Day 1 solution
│   ├── input.txt           # Your puzzle input (ignored by git)
│   └── test_input.txt      # Example input (ignored by git)
├── 2/
│   ├── CMakeLists.txt
│   ├── solve.cpp
│   ├── input.txt
│   └── test_input.txt
...
└── 12/
    ├── CMakeLists.txt
    ├── solve.cpp
    ├── input.txt
    └── test_input.txt
```

## Requirements

- C++23 compatible compiler
- CMake 3.20 or higher
- Git (for cloning submodules)

## Building

### Initial Setup

First time setup - initialize the submodule:

```bash
# Clone with submodules
git clone --recursive <repository-url>

# OR if already cloned, initialize submodules
git submodule update --init --recursive
```

### Build All Days

To build all 12 days at once:

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .
```

### Build Specific Day

To build only a specific day (e.g., day 3):

```bash
# From project root
mkdir build
cd build

# Configure with specific day
cmake .. -DAOC_DAY=3

# Build
cmake --build .
```

### Build Individual Day (Standalone)

You can also build each day independently without using the root CMake:

```bash
# Navigate to specific day
cd 3

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .
```

## Running Solutions

After building, run from the day's folder so it finds `input.txt`:

```bash
# Run day 1
cd 1
..\build\bin\Debug\day1.exe
```

## Solution Template

Each day's `solve.cpp` file contains:

- **DayN Class**: A class with `part1()` and `part2()` methods returning `std::string`
- **chrym::read_lines()**: Helper from chrym.hpp to read input files
- **chrym::time_call()**: Simple timing utility that measures execution time
- **main()**: Prints solutions with timing (wrapped in `#ifndef AOC_SOLVER_ALL`)

Example:

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

#ifndef AOC_SOLVER_ALL
int main(int argc, char** argv) {
    std::string input_path = (argc > 1) ? argv[1] : "1/input.txt";
    Day1 solver(input_path);

    auto [t1, ans1] = chrym::time_call([&]() { return solver.part1(); });
    auto [t2, ans2] = chrym::time_call([&]() { return solver.part2(); });

    std::cout << "=== Advent of Code 2025 - Day 1 ===" << std::endl;
    std::cout << "Part 1: " << ans1 << " (" << t1 << " ms)" << std::endl;
    std::cout << "Part 2: " << ans2 << " (" << t2 << " ms)" << std::endl;

    return 0;
}
#endif
```

## Adding Your Solution

1. Paste your puzzle input into `input.txt` in the day's folder
2. Open `solve.cpp` and implement `part1()` and/or `part2()`:
   - Write your solution logic
   - Store the result in the `result` variable
   - Uncomment `return std::to_string(result);`
   - Remove the `return "Not implemented";` line
3. Build and run

The `chrym::read_lines()` function loads the input file into a vector of strings (one per line).

## Timing and Output

Each solution automatically displays:
- Answer for Part 1 and Part 2
- Execution time in milliseconds using `chrym::time_call()`

Example output:
```
=== Advent of Code 2025 - Day 1 ===
Part 1: 12345 (1.23 ms)
Part 2: 67890 (2.45 ms)
```

## Compiler Warnings

The project is configured with strict compiler warnings treated as errors:

- **GCC/Clang**: `-Wall -Wextra -Wpedantic -Werror -Wshadow -Wunused`
- **MSVC**: `/W4 /WX`

## Run All Days

`solver_all.exe` runs all 12 days sequentially and displays total execution time:

```bash
# Build and run all solutions at once
.\build\bin\Debug\solver_all.exe
```

Output example:
```
╔═══════════════════════════════════════╗
║   Advent of Code 2025 - All Days      ║
╚═══════════════════════════════════════╝

=== Day  1 ===
  Part 1: 12345 (1.23 ms)
  Part 2: 67890 (2.45 ms)

=== Day  2 ===
  Part 1: 54321 (3.21 ms)
  Part 2: 98765 (4.56 ms)

...

═══════════════════════════════════════
Total time: 123 ms
```

## chrym.hpp Library

The project uses [chrym.hpp](https://github.com/Diogoperei29/advent-of-code-cpp-library) - a single-header utility library for Advent of Code with:

- **File I/O**: `read_lines()`, `read_file()`, `read_ints()`, etc.
- **Parsing**: `split()`, `is_digit()`, `to_int()`, etc.
- **Timing**: `time_call()` for simple benchmarking
- **Common algorithms**: Grid operations, pathfinding helpers, etc.

See the [library documentation](https://github.com/Diogoperei29/advent-of-code-cpp-library) for full API reference.
