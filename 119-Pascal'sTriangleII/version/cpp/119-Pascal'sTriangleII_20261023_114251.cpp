// Last updated: 10/23/2026, 11:42:51 AM
1class Solution {
2public:
3    std::vector<int> getRow(int rowIndex) {
4        std::vector<int> ans(rowIndex + 1, 1);
5        long long cnt = 1;
6
7        for (int i = 1; i <= rowIndex; i++) {
8            cnt = cnt * (rowIndex - i + 1) / i;
9            ans[i] = static_cast<int>(cnt);
10        }
11
12        return ans;
13    }
14};