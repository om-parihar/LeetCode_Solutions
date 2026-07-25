// Last updated: 7/25/2026, 10:57:11 PM
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return maxDepth;
    }
};