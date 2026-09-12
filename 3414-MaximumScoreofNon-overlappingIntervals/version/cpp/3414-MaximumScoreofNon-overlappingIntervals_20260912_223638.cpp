// Last updated: 9/12/2026, 10:36:38 PM
1class Solution1 {
2public:
3    void solve(int start, vector<vector<int>>& intervals, vector<int>& temp,long long& sum,vector<int>& ans,int csum){
4        if(csum>sum){
5            sum=csum;
6            ans=temp;
7        }
8        if(temp.size()==4) return;
9        for(int i=start;i<intervals.size();i++){
10            bool v=1;
11            for(int idx:temp){
12                    if (!(intervals[i][1] < intervals[idx][0] || intervals[i][0] > intervals[idx][1])) {
13                         v=false;
14                         break;
15                }
16            }
17            if(!v) continue;
18
19            temp.push_back(i);
20            solve(i + 1, intervals, temp, sum, ans, csum + intervals[i][2]);
21            temp.pop_back();
22        }
23    }
24    vector<int> maximumWeight(vector<vector<int>>& intervals) {
25        vector<int> ans;
26        vector<int> temp;
27        long long sum=0;
28        solve(0,intervals,temp,sum,ans,0);
29        return ans;
30    }
31};
32
33
34class Solution {
35public:
36    vector<int> maximumWeight(vector<vector<int>>& intervals) {
37        int n = intervals.size();
38        const int K = 4;
39        vector<array<long long,4>> arr(n);
40        for (int i = 0; i < n; i++) arr[i] = { intervals[i][0], intervals[i][1], intervals[i][2], i };
41        sort(arr.begin(), arr.end(), [](const array<long long,4>& a, const array<long long,4>& b) {
42            return a[0] < b[0];
43        });
44        vector<long long> ls(n);
45        for (int i = 0; i < n; i++) ls[i] = arr[i][0];
46        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(K + 1, {0, {}}));
47        for (int i = n - 1; i >= 0; i--) {
48            long long r_i = arr[i][1];
49            long long w_i = arr[i][2];
50            int orig_i = (int)arr[i][3];
51            int j = (int)(upper_bound(ls.begin(), ls.end(), r_i) - ls.begin());
52            dp[i][0] = {0, {}};
53            for (int k = 1; k <= K; k++) {
54                auto& skipOpt = dp[i + 1][k];
55                auto& baseOpt = dp[j][k - 1];
56                long long skip_w = skipOpt.first;
57                const vector<int>& skip_sel = skipOpt.second;
58                long long take_w = baseOpt.first + w_i;
59                vector<int> take_sel = baseOpt.second;
60                take_sel.push_back(orig_i);
61                sort(take_sel.begin(), take_sel.end());
62                bool takeBetter;
63                if (take_w != skip_w) takeBetter = take_w > skip_w;
64                else takeBetter = take_sel < skip_sel;
65                if (takeBetter) dp[i][k] = {take_w, take_sel};
66                else dp[i][k] = {skip_w, skip_sel};
67            }
68        }
69        return dp[0][K].second;
70    }
71};