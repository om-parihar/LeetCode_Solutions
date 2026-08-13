// Last updated: 8/13/2026, 6:32:13 PM
1class Solution {
2public:
3    bool canPartition(vector<int>& nums) {
4        int n=nums.size();
5        if(n==1) return false;
6        int mx=accumulate(nums.begin(),nums.end(),0);
7        if(mx % 2 != 0)
8            return false;
9        mx=mx/2;
10        vector<vector<bool>> dp(n, vector<bool>(mx+1, false));
11        for(int i=0;i<n;i++){
12            dp[i][0]=true;
13        }
14        if(nums[0]<=mx){
15            dp[0][nums[0]]=true;
16        }
17        for(int i=1;i<n;i++){
18            for(int j=1;j<=mx;j++){
19                bool notake=dp[i-1][j];
20                bool take=false;
21                if(nums[i]<=j){
22                    take=dp[i-1][j-nums[i]];
23                }
24                dp[i][j]=take||notake;
25            }
26        }
27        return dp[n-1][mx];
28    }
29};
30
31class Solution2 {
32public:
33    bool fun(int idx, int target, vector<int> &nums, vector<vector<int>> &dp){
34        if(target==0) return true;
35        if(idx==0) return (nums[idx]==target);
36        if(dp[idx][target]!=-1) return dp[idx][target];
37        bool notake=fun(idx-1,target,nums,dp);
38        bool take=false;
39        if(nums[idx]<=target){
40            take=fun(idx-1,target-nums[idx],nums,dp);
41        }
42        return dp[idx][target]=take || notake;
43    }
44    bool canPartition(vector<int>& nums) {
45        int n=nums.size();
46        if(n==1) return false;
47        int mx=accumulate(nums.begin(),nums.end(),0);
48        if(mx % 2 != 0)
49            return false;
50        mx=mx/2;
51        vector<vector<int>> dp(n+1,vector<int>(mx+1,-1));
52        return fun(n-1,mx,nums,dp);
53    }
54};
55
56
57class Solution1 {
58public:
59    bool fun(int idx, int target, vector<int> &nums){
60        if(target==0) return true;
61        if(idx==0) return (nums[idx]==target);
62        bool notake=fun(idx-1,target,nums);
63        bool take=false;
64        if(nums[idx]<target){
65            take=fun(idx-1,target-nums[idx],nums);
66        }
67        return take || notake;
68    }
69    bool canPartition(vector<int>& nums) {
70        int n=nums.size();
71        int mx=*max_element(nums.begin(),nums.end());
72        return fun(n-1,mx,nums);
73    }
74};