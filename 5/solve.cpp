#include "chrym.hpp"
#include <iostream>
#include <algorithm>

class Day5 {
private:
    std::vector<std::pair<uint64_t, uint64_t>> ranges;
    std::vector<uint64_t> ingredients;

public:
    Day5(std::string_view path) {
        auto lines = chrym::read_lines(path, false);
        
        std::size_t i = 0;
        while (i < lines.size() && !lines[i].empty()) {
            auto parts = chrym::split(lines[i], '-');
            uint64_t start = std::stoull(parts[0]);
            uint64_t end = std::stoull(parts[1]);
            ranges.emplace_back(start, end);
            i++;
        }
        
        i++;
        
        while (i < lines.size()) {
            if (!lines[i].empty()) {
                ingredients.push_back(std::stoull(lines[i]));
            }
            i++;
        }
        
        // Sort ranges by first element
        std::sort(ranges.begin(), ranges.end());
    }

    bool isInRanges(uint64_t value) {
        // Binary search to find the first range where first > value
        auto it = std::upper_bound(ranges.begin(), ranges.end(), value,
            [](uint64_t val, const std::pair<uint64_t, uint64_t>& range) {
                return val < range.first;
            });
        
        // Check all ranges before this position (where first <= value)
        // go backwards from the upper_bound position
        while (it != ranges.begin()) {
            --it;
            if (value >= it->first && value <= it->second) {
                return true;
            }
        }
        
        return false;
    }

    std::string part1() {
        int result = 0;
        for (const auto& val : ingredients) {
            if (isInRanges(val)) {
                result++;
            }
        }
        return std::to_string(result);
    }

    std::string part2() {
        std::vector<std::pair<uint64_t, uint64_t>> merged;
        merged.push_back(ranges[0]);
        
        for (size_t i = 1; i < ranges.size(); i++) {
            auto& last = merged.back();
            const auto& curr = ranges[i];
            
            if (curr.first <= last.second + 1) {
                last.second = std::max(last.second, curr.second);
            } else {
                merged.push_back(curr);
            }
        }
        
        uint64_t result = 0;
        for (const auto& [start, end] : merged) {
            result += (end - start + 1);
        }

        return std::to_string(result);
    }
};
