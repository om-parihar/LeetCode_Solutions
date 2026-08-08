// Last updated: 8/8/2026, 3:47:52 PM
1class Solution1 {
2public:
3    int fun(int idx, vector<int> nums,vector<int> &dp){
4        if(idx==0) return nums[idx];
5        if(idx<0) return 0;
6        if(dp[idx]!=-1) return dp[idx];
7        int pick=nums[idx]+fun(idx-2,nums,dp);
8        int notpick=0+fun(idx-1,nums,dp);
9        return dp[idx]=max(pick,notpick);
10    }
11    int rob(vector<int>& nums) {
12        int n=nums.size();
13        vector<int> dp(n+1,-1);
14        int cnt=fun(n-1,nums,dp);
15        return cnt;
16    }
17};
18
19class Solution {
20public:
21    int rob(vector<int>& nums) {
22        int n=nums.size();
23        vector<int> dp(n+1);
24        if(n==1) return nums[0];
25        dp[0]=nums[0];
26        dp[1]=max(nums[0],nums[1]);
27        for(int i=2;i<n;i++){
28            int take=nums[i]+dp[i-2];
29            int notake=0+dp[i-1];
30            dp[i]=max(take,notake);
31        }
32        return dp[n-1];
33    }
34};