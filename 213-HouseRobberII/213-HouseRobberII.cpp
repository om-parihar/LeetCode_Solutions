// Last updated: 8/8/2026, 6:38:26 PM
1class Solution1 {
2public:
3    int fun(int idx, vector<int> &n){
4        if(idx==0) return n[idx];
5        if(idx<0) return 0;
6        int take=n[idx]+fun(idx-2,n);
7        int notake=0+fun(idx-1,n);
8        return max(take,notake);
9    }
10    int rob(vector<int>& nums) {
11        int n = nums.size();
12        if(n==1) return nums[0];
13        vector<int> temp1,temp2;
14        for(int i=0;i<n;i++){
15            if(i!=n-1) temp1.push_back(nums[i]);
16            if(i!=0) temp2.push_back(nums[i]);
17        }
18        int cnt=max(fun(temp1.size()-1,temp1),fun(temp2.size()-1,temp2));
19        return cnt;
20    }
21};
22
23class Solution2 {
24public:
25    int fun(int idx, vector<int> &n,vector<int> &dp){
26        if(idx==0) return n[idx];
27        if(idx<0) return 0;
28        if(dp[idx]!=-1) return dp[idx];
29        int take=n[idx]+fun(idx-2,n,dp);
30        int notake=0+fun(idx-1,n,dp);
31        return dp[idx]=max(take,notake);
32    }
33    int rob(vector<int>& nums) {
34        int n = nums.size();
35        if(n==1) return nums[0];
36        vector<int> dp(n+1,-1);
37        vector<int> temp1,temp2;
38        for(int i=0;i<n;i++){
39            if(i!=n-1) temp1.push_back(nums[i]);
40            if(i!=0) temp2.push_back(nums[i]);
41        }
42        int cnt1=fun(temp1.size()-1,temp1,dp);
43        fill(dp.begin(),dp.end(),-1);
44        int cnt2=fun(temp2.size()-1,temp2,dp);
45        return max(cnt1,cnt2);
46    }
47};
48
49class Solution {
50public:
51    int solve(vector<int>& nums, int start, int end) {
52    vector<int> dp(end - start + 1);
53
54    dp[0] = nums[start];
55
56    if(start != end)
57        dp[1] = max(nums[start], nums[start + 1]);
58
59    for(int i = 2; i < dp.size(); i++) {
60        dp[i] = max(
61            nums[start + i] + dp[i-2],
62            dp[i-1]
63        );
64    }
65
66    return dp.back();
67}
68    int rob(vector<int>& nums) {
69    int n = nums.size();
70
71    if(n == 1)
72        return nums[0];
73
74    int case1 = solve(nums, 0, n-2);
75    int case2 = solve(nums, 1, n-1);
76
77    return max(case1, case2);
78}
79};