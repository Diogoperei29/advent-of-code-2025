#include "chrym.hpp"
#include <iostream>

class Day4 {
private:
    std::vector<std::string> lines;
    chrym::Grid2D<char> grid;

public:
    Day4(std::string_view path) {
        lines = chrym::read_lines(path, false);
        grid = chrym::parse_char_grid(lines);
    }

    std::string part1() {
        int result = 0;

        for(int y = 0; y < grid.size(); y++) {
            for(int x = 0; x < grid[0].size(); x++) {
                if (chrym::at(grid, {x,y}) == '@') {
                    int paper_counter = 0;
                    bool valid = true;
                    for (const auto& dir : chrym::DIR8) {
                        int nx = x + dir.x;
                        int ny = y + dir.y;
                        if (chrym::in_bounds(grid, nx, ny) && chrym::at(grid, {nx, ny}) == '@') {
                            paper_counter++;
                            if (paper_counter >= 4) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        //std::cout << x << ' ' << y << '\n';
                        result++;
                    }
                }
            }
        }
        return std::to_string(result);
    }

    std::string part2() {
        int result = 0;
        bool removed = true;
        while (removed) {
            removed = false;
            for(int y = 0; y < grid.size(); y++) {
                for(int x = 0; x < grid[0].size(); x++) {
                    if (chrym::at(grid, {x,y}) == '@') {
                        int paper_counter = 0;
                        bool valid = true;
                        for (const auto& dir : chrym::DIR8) {
                            int nx = x + dir.x;
                            int ny = y + dir.y;
                            if (chrym::in_bounds(grid, nx, ny) && chrym::at(grid, {nx, ny}) == '@') {
                                paper_counter++;
                                if (paper_counter >= 4) {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        if (valid) {
                            removed = true;
                            chrym::at(grid, {x, y}) = '.';
                            //std::cout << x << ' ' << y << '\n';
                            result++;
                        }
                    }
                }
            }
        } 
        return std::to_string(result);
    }
};
