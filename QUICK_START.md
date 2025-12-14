# Quick Guide: Compile and Run a Single Day

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
- **Testing**: Uncomment the test_input.txt line in solve.cpp to test first
- **Running from day folder**: Always run the executable from the day's folder (1/, 2/, etc.) so it can find input.txt
- **Benchmarks**: The executable automatically runs benchmarks after showing results

## Example Workflow

```bash
# 1. Put your input in the file
cd 3
# Edit input.txt with your puzzle input

# 2. Edit solve.cpp with your solution
# Edit solve.cpp

# 3. Build and run
cd ..
cmake -S . -B build -DAOC_DAY=3
cmake --build build
cd 3
..\build\bin\Debug\day3.exe
```
