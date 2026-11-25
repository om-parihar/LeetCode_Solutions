// Last updated: 11/25/2026, 3:39:25 PM
1class Solution {
2public:
3    vector<int> buildSuffixArray(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> vals = nums;
7        sort(vals.begin(), vals.end());
8        vals.erase(unique(vals.begin(), vals.end()), vals.end());
9
10        int N = n + 1;
11        vector<int> a(N);
12
13        for (int i = 0; i < n; i++) {
14            a[i] = lower_bound(vals.begin(), vals.end(), nums[i])
15                   - vals.begin() + 1;
16        }
17
18        a[n] = 0;
19
20        vector<int> p(N), c(N);
21        vector<int> cnt(max(N, (int)vals.size() + 1), 0);
22
23        for (int x : a) cnt[x]++;
24        for (int i = 1; i < (int)cnt.size(); i++)
25            cnt[i] += cnt[i - 1];
26
27        for (int i = N - 1; i >= 0; i--)
28            p[--cnt[a[i]]] = i;
29
30        c[p[0]] = 0;
31        int classes = 1;
32
33        for (int i = 1; i < N; i++) {
34            if (a[p[i]] != a[p[i - 1]])
35                classes++;
36            c[p[i]] = classes - 1;
37        }
38
39        vector<int> pn(N), cn(N);
40
41        for (int len = 1; len < N; len *= 2) {
42            for (int i = 0; i < N; i++) {
43                pn[i] = p[i] - len;
44                if (pn[i] < 0) pn[i] += N;
45            }
46
47            fill(cnt.begin(), cnt.begin() + classes, 0);
48
49            for (int x : pn)
50                cnt[c[x]]++;
51
52            for (int i = 1; i < classes; i++)
53                cnt[i] += cnt[i - 1];
54
55            for (int i = N - 1; i >= 0; i--)
56                p[--cnt[c[pn[i]]]] = pn[i];
57
58            cn[p[0]] = 0;
59            int newClasses = 1;
60
61            for (int i = 1; i < N; i++) {
62                pair<int, int> cur = {
63                    c[p[i]], c[(p[i] + len) % N]
64                };
65
66                pair<int, int> prev = {
67                    c[p[i - 1]], c[(p[i - 1] + len) % N]
68                };
69
70                if (cur != prev)
71                    newClasses++;
72
73                cn[p[i]] = newClasses - 1;
74            }
75
76            c.swap(cn);
77            classes = newClasses;
78
79            if (classes == N) break;
80        }
81
82        p.erase(p.begin());
83        return p;
84    }
85
86    int smallestUniqueSubarray(vector<int>& nums) {
87        int n = nums.size();
88
89        if (n == 0) return -1;
90
91        vector<int> sa = buildSuffixArray(nums);
92
93        vector<int> rank(n), lcp(n, 0);
94
95        for (int i = 0; i < n; i++)
96            rank[sa[i]] = i;
97
98        int k = 0;
99
100        for (int i = 0; i < n; i++) {
101            int r = rank[i];
102
103            if (r == 0) continue;
104
105            int j = sa[r - 1];
106
107            while (i + k < n && j + k < n &&
108                   nums[i + k] == nums[j + k]) {
109                k++;
110            }
111
112            lcp[r] = k;
113
114            if (k > 0) k--;
115        }
116
117        int ans = INT_MAX;
118
119        for (int i = 0; i < n; i++) {
120            int mx = max(lcp[i], (i + 1 < n ? lcp[i + 1] : 0));
121
122            int len = mx + 1;
123
124            if (len <= n - sa[i])
125                ans = min(ans, len);
126        }
127
128        return ans == INT_MAX ? -1 : ans;
129    }
130};