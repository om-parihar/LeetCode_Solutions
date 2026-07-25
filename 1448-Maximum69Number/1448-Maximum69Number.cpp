// Last updated: 7/25/2026, 10:57:25 PM
#include <vector>
#include <algorithm> // Required for std::reverse
#include <string>    // Required for std::stoi

class Solution {
public:
    int maximum69Number (int num) {
        std::vector<int> digits;
        std::string s = std::to_string(num);
        for (char c : s) {
            digits.push_back(c - '0');
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }
        int result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }
        return result;
    }
};