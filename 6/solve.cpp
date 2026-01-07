#include "chrym.hpp"
#include <iostream>

class Day6 {
private:
    std::vector<std::string> lines;
    std::vector<char> signals;
    std::vector<std::vector<int>> columns;

public:
    Day6(std::string_view path) {
        lines = chrym::read_lines(path, false);

        for (std::size_t i = 0; i < lines.size() - 1; i++) {
            auto parts = chrym::split(lines[i], ' ');
            // Remove empty strings from split
            parts.erase(std::remove_if(parts.begin(), parts.end(),
                [](const std::string& s) { return s.empty(); }), parts.end());
            
            columns.resize(parts.size());
            
            for (size_t j = 0; j < parts.size(); j++) {
                columns[j].push_back(std::stoi(parts[j]));
            }
        }
        
        auto lastLine = lines.back();
        for (char c : lastLine) {
            if (c == '*' || c == '+') {
                signals.push_back(c);
            }
        }
    }

    std::string part1() {
        uint64_t result = 0;

        for(std::size_t col = 0; col < columns.size(); col++) {
            if (signals[col] == '*') {
                uint64_t tmp = 1;          
                for(std::size_t i = 0; i < columns[col].size(); i++) {
                    tmp *= columns[col][i];
                }
                result += tmp;
            } else if (signals[col] == '+') {
                uint64_t tmp = 0;          
                for(std::size_t i = 0; i < columns[col].size(); i++) {
                    tmp += columns[col][i];
                }
                result += tmp;
            }
        }

        return std::to_string(result);
    }

    // f this one lol
    std::string part2() {
        uint64_t result = 0;

        auto lastLine = lines.back();
        for (char c : lastLine) {
            if (c == '*' || c == '+') {
                signals.push_back(c);
            }
        }
        
        std::vector<uint64_t> values; 
        std::size_t sign_i = 0;
        std::string tmp = "";
        // read vertical lines top to bottom -- all lines are padded with spaces (even last)
        for (std::size_t ch_i = 0; ch_i < lines[0].size() + 1; ch_i++ ) {
            tmp = "";
            for (std::size_t line_i = 0; line_i < lines.size() - 1; line_i++ ) {
                if (ch_i >= lines[line_i].size()) continue;
                if (lines[line_i][ch_i] != ' ') {
                    tmp += lines[line_i][ch_i];
                }
            }
            // found vert separator line or last vert line
            if (tmp == "" && (lastLine[ch_i] == ' ' || ch_i >= lines[0].size())) { 

                uint64_t tmp_res = 0;          
                if (signals[sign_i] == '*') {
                    tmp_res = 1;
                    for (const auto& val : values) {
                        tmp_res *= val;
                    }
                } else if (signals[sign_i] == '+') {        
                    for (const auto& val : values) {
                        tmp_res += val;
                    }
                }
                result += tmp_res;

                sign_i++;
                values.clear();
                continue;
            } else {
                values.push_back(std::stoll(tmp));
            }
        }

        return std::to_string(result);
    }
};
