// Last updated: 7/25/2026, 11:02:32 PM
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int len= 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};