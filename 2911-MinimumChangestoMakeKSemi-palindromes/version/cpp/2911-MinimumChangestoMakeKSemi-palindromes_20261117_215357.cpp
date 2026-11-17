// Last updated: 11/17/2026, 9:53:57 PM
1
2class Solution {
3public:
4    int minimumChanges(string s, int k) {
5        int n = s.size();
6
7        vector<vector<int>> cost(n, vector<int>(n, 1e9));
8
9        for (int l = 0; l < n; l++) {
10            for (int r = l + 1; r < n; r++) {
11
12                int len = r - l + 1;
13
14                for (int d = 1; d < len; d++) {
15
16                    if (len % d != 0) continue;
17
18                    int changes = 0;
19
20                    for (int rem = 0; rem < d; rem++) {
21
22                        int left = l + rem;
23                        int right = r - ((len - 1 - rem) % d);
24
25                        while (left < right) {
26                            if (s[left] != s[right]) {
27                                changes++;
28                            }
29
30                            left += d;
31                            right -= d;
32                        }
33                    }
34
35                    cost[l][r] = min(cost[l][r], changes);
36                }
37            }
38        }
39
40        vector<vector<int>> dp(k + 1,
41                               vector<int>(n + 1, 1e9));
42
43        dp[0][0] = 0;
44
45        for (int g = 1; g <= k; g++) {
46            for (int i = 2 * g; i <= n; i++) {
47
48                for (int j = 2 * (g - 1); j <= i - 2; j++) {
49
50                    dp[g][i] = min(
51                        dp[g][i],
52                        dp[g - 1][j] + cost[j][i - 1]
53                    );
54                }
55            }
56        }
57
58        return dp[k][n];
59    }
60};
61