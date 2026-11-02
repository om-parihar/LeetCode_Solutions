// Last updated: 11/2/2026, 9:59:45 AM
1class Solution {
2public:
3    int count(int i, int j, vector<vector<int>>& dp){
4        if(i==0 && j==0){
5            return 1;
6        }
7        if(i<0 || j<0) return 0;
8        if(dp[i][j]!=-1) return dp[i][j];
9        int left=count(i,j-1,dp);
10        int up=count(i-1,j,dp);
11        return dp[i][j]=left+up;
12    }
13    int uniquePaths(int m, int n) {
14        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
15        return count(m-1,n-1,dp);
16    }
17};