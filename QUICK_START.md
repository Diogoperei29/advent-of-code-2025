# Quick Guide: Compile and Run a Single Day

## Initial Setup (First Time Only)

Initialize the git submodule for the chrym library:

```bash
git submodule update --init --recursive
```

## Method 1: Using Root CMake (Recommended)

From the project root:

```bash
# Build only day 3
cmake -S . -B build -DAOC_DAY=3
cmake --build build

# Run from the day's folder so it finds input.txt
cd 3
..\build\bin\Debug\day3.exe
```

## Method 2: Standalone Build

Navigate to the specific day and build independently:

```bash
# Navigate to day folder
cd 3

# Build
cmake -S . -B build
cmake --build build

# Run (already in correct directory for input.txt)
.\build\Debug\day3.exe
```

## Tips

- **Input files**: Place your puzzle input in `input.txt` and test input in `test_input.txt`
  - These files are ignored by git to keep your inputs private
- **Testing**: Pass a custom input file path as an argument: `day3.exe path/to/test_input.txt`
- **Running from day folder**: Always run the executable from the day's folder (1/, 2/, etc.) so it can find input.txt
- **Timing**: Each run automatically shows execution time in milliseconds
- **chrym library**: Use `chrym::read_lines()` for input, `chrym::time_call()` for timing, and other utilities

## Example Workflow

```bash
# 1. Put your input in the file
cd 3
# Edit input.txt with your puzzle input

# 2. Edit solve.cpp with your solution
# Implement part1() and/or part2()
# Uncomment: return std::to_string(result);
# Remove: return "Not implemented";

# 3. Build and run
cd ..
cmake -S . -B build -DAOC_DAY=3
cmake --build build
cd 3
..\build\bin\Debug\day3.exe

# Output shows:
# === Advent of Code 2025 - Day 3 ===
# Part 1: 12345 (1.23 ms)
# Part 2: 67890 (2.45 ms)
```
