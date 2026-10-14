// Last updated: 10/14/2026, 4:23:31 PM
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        if (sum > 9 * num) return "";
5
6        string ans = "";
7
8        for (int i = 0; i < num; i++) {
9            int digit = min(9, sum);
10            ans += to_string(digit);
11            sum -= digit;
12        }
13
14        if (sum == 0) return ans;
15        return "";
16    }
17};