/*
 * Advent of Code 2025 - Interactive Solver
 * 
 * This program lets you run individual day solutions or all days at once.
 * Simply enter the day number (1-12) or "all" to run everything.
 * 
 * Usage:
 *   aoc2025.exe    - Interactive mode: prompts for which day to run
 *   aoc2025.exe 5  - Run day 5 directly
 *   aoc2025.exe all - Run all days
 */

#define AOC_SOLVER_ALL

#include "chrym.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>

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

// Resolve input file path relative to current working directory, with fallback to parent - because i kept forgetting
static std::string resolveInputPath(int dayNumber, const std::string& inputType) {
    namespace fs = std::filesystem;
    fs::path rel = fs::path(std::to_string(dayNumber)) / (inputType + ".txt");
    if (fs::exists(rel)) return rel.string();

    fs::path parentRel = fs::path("..") / rel;
    if (fs::exists(parentRel)) return parentRel.string();

    std::cerr << "Input file not found: " << rel.string() << " or " << parentRel.string() << std::endl;
    return rel.string();
}

// Helper function to run a day's solution with benchmarking
template<typename DayClass>
void runDay(int dayNumber, const std::string& inputPath) {
    DayClass solver(inputPath);
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "Day " << dayNumber << " Solution" << std::endl;
    std::cout << "========================================" << std::endl;
    
    auto [t1, ans1] = chrym::time_call([&]() { return solver.part1(); });
    auto [t2, ans2] = chrym::time_call([&]() { return solver.part2(); });
    
    std::cout << "Part 1: " << ans1 << " (" << t1 << " ms)" << std::endl;
    std::cout << "Part 2: " << ans2 << " (" << t2 << " ms)" << std::endl;
    std::cout << "Total:  " << (t1 + t2) << " ms" << std::endl;
}

void runSingleDay(int day, const std::string& inputType) {
    std::string inputPath = resolveInputPath(day, inputType);

    switch(day) {
        case 1:  runDay<Day1>(1, inputPath); break;
        case 2:  runDay<Day2>(2, inputPath); break;
        case 3:  runDay<Day3>(3, inputPath); break;
        case 4:  runDay<Day4>(4, inputPath); break;
        case 5:  runDay<Day5>(5, inputPath); break;
        case 6:  runDay<Day6>(6, inputPath); break;
        case 7:  runDay<Day7>(7, inputPath); break;
        case 8:  runDay<Day8>(8, inputPath); break;
        case 9:  runDay<Day9>(9, inputPath); break;
        case 10: runDay<Day10>(10, inputPath); break;
        case 11: runDay<Day11>(11, inputPath); break;
        case 12: runDay<Day12>(12, inputPath); break;
        default:
            std::cout << "Invalid day number. Please enter a number between 1 and 12." << std::endl;
    }
}

void runAllDays(const std::string& inputType) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Advent of Code 2025 - All Days" << std::endl;
    std::cout << "========================================" << std::endl;
    
    auto totalStart = std::chrono::high_resolution_clock::now();
    
    runDay<Day1>(1, resolveInputPath(1, inputType));
    runDay<Day2>(2, resolveInputPath(2, inputType));
    runDay<Day3>(3, resolveInputPath(3, inputType));
    runDay<Day4>(4, resolveInputPath(4, inputType));
    runDay<Day5>(5, resolveInputPath(5, inputType));
    runDay<Day6>(6, resolveInputPath(6, inputType));
    runDay<Day7>(7, resolveInputPath(7, inputType));
    runDay<Day8>(8, resolveInputPath(8, inputType));
    runDay<Day9>(9, resolveInputPath(9, inputType));
    runDay<Day10>(10, resolveInputPath(10, inputType));
    runDay<Day11>(11, resolveInputPath(11, inputType));
    runDay<Day12>(12, resolveInputPath(12, inputType));
    
    auto totalEnd = std::chrono::high_resolution_clock::now();
    auto totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(totalEnd - totalStart);
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "Total execution time: " << totalDuration.count() << " ms" << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string dayInput;
    std::string inputType;
    
    // check arguments 
    if (argc > 1) {
        dayInput = argv[1];
        inputType = (argc > 2) ? argv[2] : "input";
    } else {
        std::cout << "Advent of Code 2025 Solver" << std::endl;
        std::cout << "Enter day (1-12 or 'all'): ";
        std::getline(std::cin, dayInput);
        
        std::cout << "Enter input type ('input' or 'test'): ";
        std::getline(std::cin, inputType);
    }
    
    std::transform(inputType.begin(), inputType.end(), inputType.begin(), 
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    if (inputType == "test") {
        inputType = "test_input";
    } 
    if (inputType != "input" && inputType != "test_input") {
        inputType = "input";  // default to input
    }
    
    // Convert day input to lowercase and trim
    std::transform(dayInput.begin(), dayInput.end(), dayInput.begin(), 
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    dayInput.erase(0, dayInput.find_first_not_of(" \t\n\r"));
    dayInput.erase(dayInput.find_last_not_of(" \t\n\r") + 1);
    
    if (dayInput == "all") {
        runAllDays(inputType);
    } else {
        try {
            int day = std::stoi(dayInput);
            if (day >= 1 && day <= 12) {
                runSingleDay(day, inputType);
            } else {
                std::cout << "Invalid day number. Please enter a number between 1 and 12." << std::endl;
                return 1;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Invalid input. Please enter a day number (1-12) or 'all'." << std::endl;
            return 1;
        }
    }
    
    return 0;
}
