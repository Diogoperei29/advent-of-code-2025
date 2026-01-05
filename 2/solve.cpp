#include "chrym.hpp"
#include <iostream>

class Day2 {
private:
    std::string line;

public:
    Day2(std::string_view path) {
        line = chrym::read_file(path);
    }

    std::string part1() {
        uint64_t result = 0;
        std::vector<std::string> ranges = chrym::split(line, ',');

        for (const auto &range : ranges) {
            std::vector<std::string> range_str = chrym::split(range, '-');
            std::string min = range_str[0];
            std::string max = range_str[1];
            uint64_t min_i = static_cast<uint64_t>(std::stoull(min));
            uint64_t max_i = static_cast<uint64_t>(std::stoull(max));
            uint64_t currValue_i = min_i;
            //if (min.length() % 2 != 0) currValue_i = std::pow(10, static_cast<int>(min.length())); // Set currValue to closest even length value to range min (might be lower)

            // Closest pattern to currValue
            std::string currValue = std::to_string(currValue_i);
            currValue = (currValue.length() > 1) ? currValue.substr(0, static_cast<int>(currValue.length()) / 2 ) : "1";
            currValue = currValue + currValue;
            currValue_i = static_cast<uint64_t>(std::stoull(currValue));

            while ( currValue_i <= max_i ) {
                if (chrym::between_inclusive(currValue_i, min_i, max_i)) {
                    result += currValue_i;
                }

                currValue = currValue.substr(0, static_cast<int>(currValue.length()) / 2 );
                currValue = std::to_string( static_cast<uint64_t>(std::stoull(currValue)) + 1 );
                currValue = currValue + currValue;
                currValue_i = static_cast<uint64_t>(std::stoull(currValue));
            }
        }

        return std::to_string(result);
    }

    bool HasRepeatingPattern(uint64_t num) {
        std::string str = std::to_string(num);
        int len = static_cast<int>(str.length());
        
        // single digit repeated - special case
        if (len >= 2) {
            char firstChar = str[0];
            bool allSame = true;
            for (int i = 1; i < len; ++i) {
                if (str[i] != firstChar) {
                    allSame = false;
                    break;
                }
            }
            if (allSame) {
                return true;
            }
        }
        
        // Try pattern lengths from 2 to len/2 (must repeat at least twice)
        for (int patternLen = 2; patternLen <= len / 2; ++patternLen) {
            // Length must be divisible by pattern length for complete repetition
            if (len % patternLen != 0) {
                continue;
            }
            
            // Extract the pattern from the start
            std::string pattern = str.substr(0, patternLen);
            
            // Check if entire string is this pattern repeated
            bool matches = true;
            for (int i = 0; i < len; ++i) {
                if (str[i] != pattern[i % patternLen]) {
                    matches = false;
                    break;
                }
            }
            
            if (matches) {
                return true;
            }
        }
        
        return false;
    }

    std::string part2() {
        uint64_t result = 0;
        std::vector<std::string> ranges = chrym::split(line, ',');

        for (const auto &range : ranges) {
            std::vector<std::string> range_str = chrym::split(range, '-');
            uint64_t min_i = static_cast<uint64_t>(std::stoull(range_str[0]));
            uint64_t max_i = static_cast<uint64_t>(std::stoull(range_str[1]));
            //std::cout << min_i << " " << max_i << '\n';
            for (uint64_t idx = min_i; idx <= max_i; idx++) {
                if (HasRepeatingPattern(idx)) {
                    //std::cout << "added " << idx << '\n'; 
                    result += idx;
                }
            }

        }

        return std::to_string(result);
    }
};
