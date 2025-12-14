#include "chrym.hpp"
#include <iostream>

class Day8 {
private:
    std::vector<std::string> lines;

public:
    Day8(std::string_view path) {
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input_path = (argc > 1) ? argv[1] : "8/input.txt";

    Day8 solver(input_path);

    auto [t1, ans1] = chrym::time_call([&]() { return solver.part1(); });
    auto [t2, ans2] = chrym::time_call([&]() { return solver.part2(); });

    std::cout << "=== Advent of Code 2025 - Day 8 ===" << std::endl;
    std::cout << "Part 1: " << ans1 << " (" << t1 << " ms)" << std::endl;
    std::cout << "Part 2: " << ans2 << " (" << t2 << " ms)" << std::endl;

    return 0;
}
#endif
