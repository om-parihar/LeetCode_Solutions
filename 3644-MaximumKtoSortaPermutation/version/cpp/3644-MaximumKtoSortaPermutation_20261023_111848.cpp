// Last updated: 10/23/2026, 11:18:48 AM
1class Solution {
2public:
3    int sortPermutation(vector<int>& nums) {
4        int ans = -1;
5        for (int i = 0; i < nums.size(); ++i) {
6            if (i != nums[i]) {
7                ans &= nums[i];
8            }
9        }
10        return max(ans, 0);
11    }
12};