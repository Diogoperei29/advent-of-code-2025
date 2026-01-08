#include "chrym.hpp"
#include <iostream>

class Day7 {
private:
    std::vector<std::string> lines;
    std::vector<std::string> lines_p2;
    int S_x = 0;

public:
    Day7(std::string_view path) {
        lines = chrym::read_lines(path, false);
        lines_p2 = lines; // deep copy before changing in p1
        
        for(const auto& ch : lines[0]) {
            if (ch == 'S') break;
            S_x++;
        }
    }

    void printLines(std::vector<std::string> grid) const {
        for (const auto& line : grid) {
            std::cout << line << '\n';
        }
    }

    // this is a dumb brute-force approach - check p2
    std::string part1() {
        int result = 0;

        for(std::size_t line_i = 1; line_i < lines.size(); line_i++) {
            for(std::size_t ch_i = 0; ch_i < lines[0].size(); ch_i++) {
                if (lines[line_i][ch_i] == '.' && (lines[line_i - 1][ch_i] == '|' || lines[line_i - 1][ch_i] == 'S')) {
                    lines[line_i][ch_i] = '|';
                } else if (lines[line_i][ch_i] == '^' && (lines[line_i - 1][ch_i] == '|' || lines[line_i - 1][ch_i] == 'S')) {
                    if (ch_i-1 >= 0 && lines[line_i][ch_i-1] == '.') {
                        lines[line_i][ch_i-1] = '|';
                    }
                    if (ch_i+1 < lines[0].size() && lines[line_i][ch_i+1] == '.') {
                        lines[line_i][ch_i+1] = '|';
                    }
                    result++;
                }
            }
        }

        return std::to_string(result);
    }

    std::vector<std::vector<int64_t>> memo;

    int64_t runNextLine(std::size_t line_i, std::size_t ch_i) {
        if (ch_i < 0 || ch_i >= lines_p2[0].size()) return 0;
        if (line_i >= lines_p2.size()) return 1;

        if (memo[line_i][ch_i] != -1) return memo[line_i][ch_i];

        int64_t result = 0;
        if (lines_p2[line_i][ch_i] == '.' || lines_p2[line_i][ch_i] == 'S') {
            result = runNextLine(line_i + 1, ch_i);
        } else if (lines_p2[line_i][ch_i] == '^') {
            result = runNextLine(line_i + 1, ch_i - 1) + runNextLine(line_i + 1, ch_i + 1);
        }

        memo[line_i][ch_i] = result;
        return result; 
    }

    std::string part2() {
        int64_t result = 0;
        // assign -1 to DP members (this was easier than maps tbh)
        memo.assign(lines_p2.size(), std::vector<int64_t>(lines_p2[0].size(), -1)); 
        result = runNextLine(0, S_x);
        return std::to_string(result);
    }
};
