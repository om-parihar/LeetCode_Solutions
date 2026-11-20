// Last updated: 11/20/2026, 6:09:24 PM
1
2class Solution {
3public:
4    int maxSelectedElements(vector<int>& nums) {
5        sort(nums.begin(), nums.end());
6
7        unordered_map<int, int> dp;
8        int ans = 0;
9
10        for (int x : nums) {
11            int notTake = dp[x - 1] + 1;
12            int take = dp[x] + 1;
13
14            dp[x] = max(dp[x], notTake);
15            dp[x + 1] = max(dp[x + 1], take);
16
17            ans = max({ans, dp[x], dp[x + 1]});
18        }
19
20        return ans;
21    }
22};
23