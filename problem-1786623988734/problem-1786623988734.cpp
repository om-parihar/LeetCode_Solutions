// Last updated: 8/13/2026, 5:56:28 PM
1class Solution {
2public:
3    bool fun(int idx, int target, vector<int> &nums, vector<vector<int>> &dp){
4        if(target==0) return true;
5        if(idx==0) return (nums[idx]==target);
6        if(dp[idx][target]!=-1) return dp[idx][target];
7        bool notake=fun(idx-1,target,nums,dp);
8        bool take=false;
9        if(nums[idx]<=target){
10            take=fun(idx-1,target-nums[idx],nums,dp);
11        }
12        return dp[idx][target]=take || notake;
13    }
14    bool canPartition(vector<int>& nums) {
15        int n=nums.size();
16        if(n==1) return false;
17        int mx=accumulate(nums.begin(),nums.end(),0);
18        if(mx % 2 != 0)
19            return false;
20        mx=mx/2;
21        vector<vector<int>> dp(n+1,vector<int>(mx+1,-1));
22        return fun(n-1,mx,nums,dp);
23    }
24};
25
26
27class Solution1 {
28public:
29    bool fun(int idx, int target, vector<int> &nums){
30        if(target==0) return true;
31        if(idx==0) return (nums[idx]==target);
32        bool notake=fun(idx-1,target,nums);
33        bool take=false;
34        if(nums[idx]<target){
35            take=fun(idx-1,target-nums[idx],nums);
36        }
37        return take || notake;
38    }
39    bool canPartition(vector<int>& nums) {
40        int n=nums.size();
41        int mx=*max_element(nums.begin(),nums.end());
42        return fun(n-1,mx,nums);
43    }
44};