/*
 * Advent of Code 2025 - All Solutions Runner
 * 
 * This file runs all day solutions in sequence with simple benchmarking.
 * Each day's solution is defined in its respective folder (1/solve.cpp, 2/solve.cpp, etc.)
 * 
 * Usage:
 *   solver_all.exe    - Run all solutions with timing
 */

#define AOC_SOLVER_ALL

#include "chrym.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

// Include all day solutions
#include "1/solve.cpp"
#include "2/solve.cpp"
#include "3/solve.cpp"
#include "4/solve.cpp"
#include "5/solve.cpp"
#include "6/solve.cpp"
#include "7/solve.cpp"
#include "8/solve.cpp"
#include "9/solve.cpp"
#include "10/solve.cpp"
#include "11/solve.cpp"
#include "12/solve.cpp"

// Helper function to run a day's solution
template<typename DayClass>
void runDay(int dayNumber, const std::string& inputPath) {
    DayClass solver(inputPath);
    
    std::cout << "=== Day " << std::setw(2) << dayNumber << " ===" << std::endl;
    
    auto [t1, ans1] = chrym::time_call([&]() { return solver.part1(); });
    auto [t2, ans2] = chrym::time_call([&]() { return solver.part2(); });
    
    std::cout << "  Part 1: " << ans1 << " (" << t1 << " ms)" << std::endl;
    std::cout << "  Part 2: " << ans2 << " (" << t2 << " ms)" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << "╔═══════════════════════════════════════╗" << std::endl;
    std::cout << "║   Advent of Code 2025 - All Days      ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;
    
    auto totalStart = std::chrono::high_resolution_clock::now();
    
    runDay<Day1>(1, "1/input.txt");
    runDay<Day2>(2, "2/input.txt");
    runDay<Day3>(3, "3/input.txt");
    runDay<Day4>(4, "4/input.txt");
    runDay<Day5>(5, "5/input.txt");
    runDay<Day6>(6, "6/input.txt");
    runDay<Day7>(7, "7/input.txt");
    runDay<Day8>(8, "8/input.txt");
    runDay<Day9>(9, "9/input.txt");
    runDay<Day10>(10, "10/input.txt");
    runDay<Day11>(11, "11/input.txt");
    runDay<Day12>(12, "12/input.txt");
    
    auto totalEnd = std::chrono::high_resolution_clock::now();
    auto totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(totalEnd - totalStart);
    
    std::cout << "═══════════════════════════════════════" << std::endl;
    std::cout << "Total time: " << totalDuration.count() << " ms" << std::endl;
    
    return 0;
}
