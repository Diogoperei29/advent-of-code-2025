#include "chrym.hpp"
#include <iostream>

class Day1 {
private:
    std::vector<std::string> lines;
    int currPos = 50;

public:
    Day1(std::string_view path) {
        lines = chrym::read_lines(path, false);
    }

    std::string part1() {
        int result = 0;
        currPos = 50;
        char dir;
        int rots = 0;

        for (const auto &line : lines) {
            if (line.empty()) continue;
            
            dir = line[0];
            rots = std::stoi(line.substr(1));

            if (dir == 'L') {
                currPos = ((currPos - rots) % 100 + 100) % 100;
            } else { // 'R'
                currPos = (currPos + rots) % 100;
            }
            if (currPos == 0) result++;
        }
        return std::to_string(result);
    }

    std::string part2() {
        int result = 0;
        currPos = 50;
        char dir;
        int rots = 0;

        for (const auto &line : lines) {
            if (line.empty()) continue;
            
            dir = line[0];
            rots = std::stoi(line.substr(1));

            if (dir == 'L') {
                int crosses = 0;
                if (currPos == 0) {
                    crosses = rots / 100; // only count full loops back to 0
                } else if (rots >= currPos) {
                    crosses = 1 + (rots - currPos) / 100; // first hit at step = currPos, then every 100 steps
                }
                result += crosses;
                currPos = ((currPos - rots) % 100 + 100) % 100;
            } else { // 'R'
                // hits 0 after (100 - currPos) steps, then every 100 steps
                int crosses = (currPos + rots) / 100;
                result += crosses;
                currPos = (currPos + rots) % 100;
            }
            std::cout << line << ' ' << currPos << ' ' << result << '\n';
        }
        return std::to_string(result);
    }
};
