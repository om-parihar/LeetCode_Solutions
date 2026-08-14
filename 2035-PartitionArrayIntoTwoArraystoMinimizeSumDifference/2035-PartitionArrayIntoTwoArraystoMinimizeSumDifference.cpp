// Last updated: 8/15/2026, 12:49:27 AM
1class Solution {
2public:
3    int minimumDifference(vector<int>& nums) {
4        int n = nums.size();
5        int N = n / 2;
6
7        vector<vector<int>> left(N + 1);
8        vector<vector<int>> right(N + 1);
9
10        for (int mask = 0; mask < (1 << N); mask++) {
11            int cnt = 0, sum = 0;
12
13            for (int i = 0; i < N; i++) {
14                if (mask & (1 << i)) {
15                    cnt++;
16                    sum += nums[i];
17                }
18            }
19
20            left[cnt].push_back(sum);
21        }
22
23        for (int mask = 0; mask < (1 << N); mask++) {
24            int cnt = 0, sum = 0;
25
26            for (int i = 0; i < N; i++) {
27                if (mask & (1 << i)) {
28                    cnt++;
29                    sum += nums[N + i];
30                }
31            }
32
33            right[cnt].push_back(sum);
34        }
35
36        for (int i = 0; i <= N; i++) {
37            sort(right[i].begin(), right[i].end());
38        }
39
40        int total = accumulate(nums.begin(), nums.end(), 0);
41        int ans = INT_MAX;
42
43        for (int cnt = 0; cnt <= N; cnt++) {
44            int need = N - cnt;
45
46            for (int sum1 : left[cnt]) {
47
48                int target = total / 2 - sum1;
49
50                auto it = lower_bound(
51                    right[need].begin(),
52                    right[need].end(),
53                    target
54                );
55
56                if (it != right[need].end()) {
57                    int sum2 = *it;
58                    ans = min(ans, abs(total - 2 * (sum1 + sum2)));
59                }
60
61                if (it != right[need].begin()) {
62                    --it;
63                    int sum2 = *it;
64                    ans = min(ans, abs(total - 2 * (sum1 + sum2)));
65                }
66            }
67        }
68
69        return ans;
70    }
71};