// Last updated: 11/13/2026, 8:12:38 AM
1
2class Solution {
3public:
4    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
5        int n = nums.size();
6        long long ans = 0, cost = 0;
7
8        deque<pair<int, int>> dq;
9
10        int j = n - 1;
11
12        for (int i = n - 1; i >= 0; i--) {
13            int num = nums[i];
14            int cnt = 1;
15
16            while (!dq.empty() && dq.back().first < num) {
17                auto [val, freq] = dq.back();
18                dq.pop_back();
19
20                cnt += freq;
21                cost += 1LL * (num - val) * freq;
22            }
23
24            dq.push_back({num, cnt});
25
26            while (cost > k) {
27                auto [val, freq] = dq.front();
28                dq.pop_front();
29
30                cost -= val - nums[j];
31                j--;
32
33                if (freq > 1) {
34                    dq.push_front({val, freq - 1});
35                }
36            }
37
38            ans += j - i + 1;
39        }
40
41        return ans;
42    }
43};
44