// Last updated: 11/2/2026, 10:16:07 AM
1class Solution {
2public:
3    int count(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
4        if(i<0 || j<0) return 0;
5        if(obstacleGrid[i][j]==1) return 0;
6        if(i==0 && j==0) return 1;
7        if(dp[i][j]!=-1) return dp[i][j];
8        int up=count(i-1,j,obstacleGrid,dp);
9        int left=count(i,j-1,obstacleGrid,dp);
10        return dp[i][j]=up+left;
11    }
12    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
13        int n=obstacleGrid.size();
14        int m=obstacleGrid[0].size();
15        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
16        return count(n-1,m-1,obstacleGrid,dp);
17    }
18};