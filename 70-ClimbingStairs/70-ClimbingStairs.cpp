// Last updated: 8/8/2026, 12:17:50 PM
1class Solution1 {
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
15
16class Solution {
17public:
18    int climbStairs(int n) {
19        vector<int> dp(n+1,-1);
20        dp[0]=1;
21        dp[1]=1;
22        for(int i=2;i<=n;i++){
23            dp[i]=dp[i-1]+dp[i-2];
24        }
25        return dp[n];
26    }
27};