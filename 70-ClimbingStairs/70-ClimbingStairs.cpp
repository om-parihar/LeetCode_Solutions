// Last updated: 8/8/2026, 12:06:10 PM
1class Solution {
2public:
3    int climb(int n,vector<int> &dp){
4        if(n==0) return 1;
5        if(n==1) return 1;
6        if(dp[n]!=-1) return dp[n];
7        return dp[n]=climb(n-1,dp)+climb(n-2,dp);
8    }
9    int climbStairs(int n) {
10        vector<int> dp(n+1,-1);
11        int cnt=climb(n,dp);
12        return cnt;
13    }
14};