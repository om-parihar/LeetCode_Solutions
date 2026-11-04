// Last updated: 11/4/2026, 10:36:13 PM
1
2class Solution {
3public:
4    multiset<int> low, high;
5    long long sumLow = 0, sumHigh = 0;
6
7    void add(int val) {
8        if (low.empty() || val <= *low.rbegin()) {
9            low.insert(val);
10            sumLow += val;
11        } else {
12            high.insert(val);
13            sumHigh += val;
14        }
15
16        balance();
17    }
18
19    void remove(int val) {
20        auto it = low.find(val);
21
22        if (it != low.end()) {
23            low.erase(it);
24            sumLow -= val;
25        } else {
26            it = high.find(val);
27            high.erase(it);
28            sumHigh -= val;
29        }
30
31        balance();
32    }
33
34    void balance() {
35        while (low.size() > high.size() + 1) {
36            int val = *low.rbegin();
37            low.erase(prev(low.end()));
38            sumLow -= val;
39
40            high.insert(val);
41            sumHigh += val;
42        }
43
44        while (low.size() < high.size()) {
45            int val = *high.begin();
46            high.erase(high.begin());
47            sumHigh -= val;
48
49            low.insert(val);
50            sumLow += val;
51        }
52    }
53
54    long long getCost() {
55        long long median = *low.rbegin();
56
57        return median * low.size() - sumLow
58             + sumHigh - median * high.size();
59    }
60
61    long long count(int i, int k, vector<int>& nums,
62                    int x, vector<long long>& cost,
63                    vector<vector<long long>>& dp) {
64
65        if (k == 0) return 0;
66
67        if (i + x > nums.size()) return LLONG_MAX / 2;
68
69        if (dp[i][k] != -1) return dp[i][k];
70
71        long long notake = count(i + 1, k, nums, x, cost, dp);
72
73        long long take = cost[i] +
74                         count(i + x, k - 1, nums, x, cost, dp);
75
76        return dp[i][k] = min(take, notake);
77    }
78
79    long long minOperations(vector<int>& nums, int x, int k) {
80        int n = nums.size();
81
82        vector<long long> cost(n, 0);
83
84        low.clear();
85        high.clear();
86        sumLow = sumHigh = 0;
87
88        for (int i = 0; i < x; i++) {
89            add(nums[i]);
90        }
91
92        cost[0] = getCost();
93
94        for (int i = 1; i + x <= n; i++) {
95            remove(nums[i - 1]);
96            add(nums[i + x - 1]);
97
98            cost[i] = getCost();
99        }
100
101        vector<vector<long long>> dp(
102            n + 1, vector<long long>(k + 1, -1)
103        );
104
105        return count(0, k, nums, x, cost, dp);
106    }
107};
108