// Last updated: 10/26/2026, 10:34:12 AM
1class Solution {
2public:
3    int count(int i, int n,vector<vector<int>>& dp){
4        if(n==0){
5            return 0;
6        }
7        if(i==0) return INT_MAX/2;
8        if(dp[i][n]!=-1) return dp[i][n];
9        int notake=count(i-1,n,dp);
10        int take=INT_MAX/2;
11        if(i*i<=n){
12            take=1+count(i,(n-(i*i)),dp);
13        }
14        return dp[i][n]=min(take,notake);
15    }
16    int numSquares(int n) {
17        vector<vector<int>> dp(sqrt(n) + 1, vector<int>(n + 1, -1));
18        return count(sqrt(n),n,dp);
19    }
20};