#include "chrym.hpp"
#include <iostream>

class Day3 {
private:
    std::vector<std::string> lines;
    std::vector<std::vector<uint8_t>> banks;

public:
    Day3(std::string_view path) {
        lines = chrym::read_lines(path, false);

        banks.reserve(lines.size());
        for (const auto &line : lines) {
            std::vector<uint8_t> tmp_bank;
            tmp_bank.reserve(line.length());
            for (const auto &ch : line) {
                tmp_bank.push_back(static_cast<uint8_t>(ch - '0'));
            }
            banks.push_back(tmp_bank);
        }
    }

    // brute force
    std::string part1() {
        int result = 0;
        int max_val = 0;
        
        for (const auto &bank : banks) {
            max_val = 0;
            for(int ch1 = 0; ch1 < static_cast<int>(bank.size()); ch1++) {
                for(int ch2 = ch1+1; ch2 < static_cast<int>(bank.size()); ch2++) {
                    int num = 10*bank[ch1] + bank[ch2];
                    if ( num > max_val ) max_val = num;
                }
            }
            // std::cout << max_val << '\n';
            result += max_val;
        }
        return std::to_string(result);
    }


    // greedy
    std::string part2() {
        const int TARGET_LENGTH = 12;
        int64_t result = 0;
        int64_t max_val = 0;
        int max_id = 0;
        int max_pos = -1;
        
        for (const auto &bank : banks) {
            max_val = 0;
            int curr_pos = 0;
            for(int ch = 0; ch < TARGET_LENGTH; ch++) {
                max_id = 0;
                max_pos = -1;
                for (int pos = curr_pos; pos < static_cast<int>(bank.size())-TARGET_LENGTH+ch+1; pos++ ) {
                    if (bank[pos] > max_id) {
                        max_pos = pos;
                        max_id = bank[pos];
                    }
                }  
                max_val +=  pow(10, TARGET_LENGTH - ch - 1) * max_id ;
                curr_pos = max_pos + 1;
            }
            result += max_val;
        }
        return std::to_string(result);
    }
};
