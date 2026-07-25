// Last updated: 7/25/2026, 11:00:56 PM
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            int next = 0;
            while (n > 0) {
                int digit = n % 10;
                next += digit * digit;
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};
