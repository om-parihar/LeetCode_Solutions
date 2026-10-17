// Last updated: 10/17/2026, 8:48:24 AM
1class Solution {
2public:
3    int count(int i) {
4        int sum = 0;
5        while (i) {
6            int digit = i % 10;
7            sum += digit;
8            i = i / 10;
9        }
10        return sum;
11    }
12
13    int minSwaps(vector<int>& nums) {
14        vector<tuple<int, int, int>> a;
15
16        for (int i = 0; i < nums.size(); i++) {
17            int dsum = count(nums[i]);
18            a.push_back({dsum, nums[i], i});
19        }
20
21        sort(a.begin(), a.end());
22
23        int n = a.size();
24        vector<int> vis(n, 0);
25        int cnt = 0;
26
27        for (int i = 0; i < n; i++) {
28            if (vis[i] || get<2>(a[i]) == i)
29                continue;
30
31            int j = i;
32            int cycle = 0;
33
34            while (!vis[j]) {
35                vis[j] = 1;
36                j = get<2>(a[j]);
37                cycle++;
38            }
39
40            if (cycle > 1)
41                cnt += cycle - 1;
42        }
43
44        return cnt;
45    }
46};