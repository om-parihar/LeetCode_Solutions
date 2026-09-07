// Last updated: 9/7/2026, 7:35:51 PM
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        const int MOD = 1e9 + 7;
5        int n = s.size();
6
7        vector<long long> dp(n + 1, 0);
8        vector<int> last(26, -1);
9
10        dp[0] = 1;
11
12        for (int i = 1; i <= n; i++) {
13            int c = s[i - 1] - 'a';
14
15            dp[i] = (2 * dp[i - 1]) % MOD;
16
17            if (last[c] != -1) {
18                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
19            }
20
21            last[c] = i;
22        }
23
24        return (dp[n] - 1 + MOD) % MOD;
25    }
26};