// Last updated: 7/25/2026, 11:00:04 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
        return false;
    }
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}
};