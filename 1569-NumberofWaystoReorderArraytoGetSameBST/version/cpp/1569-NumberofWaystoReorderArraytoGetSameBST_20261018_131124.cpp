// Last updated: 10/18/2026, 1:11:24 PM
1class Solution {
2private:
3    long long MOD = 1e9 + 7;
4    vector<vector<long long>> comb;
5
6    long long dfs(vector<int>& nums) {
7        int n = nums.size();
8        if (n <= 2) return 1;
9
10        int root = nums[0];
11        vector<int> left, right;
12
13        for (int i = 1; i < n; ++i) {
14            if (nums[i] < root) {
15                left.push_back(nums[i]);
16            } else {
17                right.push_back(nums[i]);
18            }
19        }
20
21        long long leftWays = dfs(left);
22        long long rightWays = dfs(right);
23
24        int L = left.size();
25        int R = right.size();
26
27        long long ways = (comb[L + R][L] * leftWays) % MOD;
28        ways = (ways * rightWays) % MOD;
29
30        return ways;
31    }
32
33public:
34    int numOfWays(vector<int>& nums) {
35        int n = nums.size();
36
37        comb.assign(n + 1, vector<long long>(n + 1, 0));
38        for (int i = 0; i <= n; ++i) {
39            comb[i][0] = 1;
40            for (int j = 1; j <= i; ++j) {
41                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
42            }
43        }
44
45        return (dfs(nums) - 1 + MOD) % MOD;
46    }
47};