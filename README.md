# Advent of Code 2025

My personal solutions to the 2025 Advent of Code coding challenges, in C++.

## Project Structure

```
advent-of-code-2025/
├── CMakeLists.txt          # Root CMake configuration
├── solver_all.cpp          # Run all days at once
├── 1/
│   ├── CMakeLists.txt      # Day 1 CMake (can be used standalone)
│   ├── solve.cpp           # Day 1 solution
│   ├── input.txt           # Your puzzle input
│   └── test_input.txt      # Example input
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
- Internet connection (for downloading Google Benchmark)

## Building

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

- **DayN Class**: A class with `part1()` and `part2()` methods
- **readFile()**: Helper to read `input.txt` or `test_input.txt`
- **Benchmarks**: Google Benchmark integration (runs once per solution)
- **main()**: Prints solutions and runs benchmarks

Example:

```cpp
class Day1 {
private:
    std::string readFile(const std::string& filename) {
        // Reads file into string
    }
public:
    std::string part1() {
        std::string input = readFile("input.txt");
        // Your solution logic
        return std::to_string(result);
    }

    std::string part2() {
        std::string input = readFile("input.txt");
        // Your solution logic
        return std::to_string(result);
    }
};
```

## Benchmark Options

Benchmarks run once by default. Pass options to customize:

```bash
# Run with repetitions
day1.exe --benchmark_repetitions=10

# Filter specific benchmarks
day1.exe --benchmark_filter=Part1
```

## Compiler Warnings

The project is configured with strict compiler warnings treated as errors:

- **GCC/Clang**: `-Wall -Wextra -Wpedantic -Werror -Wshadow -Wunused`
- **MSVC**: `/W4 /WX`

## Adding Your Solution

1. Paste your puzzle input into `input.txt` in the day's folder
2. Open `solve.cpp` and implement `part1()` and `part2()`
3. Build and run

The `readFile()` method loads the input file content into a string for processing.

## Run All Days

```bash
# Build and run all solutions at once
.\build\bin\Debug\solver_all.exe

# With benchmarks
.\build\bin\Debug\solver_all.exe --benchmark
```
