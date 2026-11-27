// Last updated: 11/27/2026, 1:55:19 PM
1class Solution {
2public:
3    int maximumSaleItems(vector<vector<int>>& items, int budget) {
4        int n = items.size();
5
6        vector<int> dp(budget + 1, 0);
7        int mn = INT_MAX;
8
9        for (int i = 0; i < n; i++) {
10            int factor = items[i][0];
11            int price = items[i][1];
12
13            mn = min(mn, price);
14
15            int freeItems = 0;
16
17            for (int j = 0; j < n; j++) {
18                if (i != j && items[j][0] % factor == 0) {
19                    freeItems++;
20                }
21            }
22
23            for (int b = budget; b >= price; b--) {
24                dp[b] = max(dp[b],
25                            dp[b - price] + freeItems + 1);
26            }
27        }
28
29        int ans = 0;
30
31        for (int b = 0; b <= budget; b++) {
32            ans = max(ans, dp[b] + (budget - b) / mn);
33        }
34
35        return ans;
36    }
37};