// Last updated: 8/10/2026, 4:20:33 PM
1class Solution1 {
2public:
3    int count(int i, int j, vector<vector<int>>& obstacleGrid){
4        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
5        if(i==0 && j==0) return 1;
6        if(i<0 || j<0) return 0;
7        int up=count(i-1,j,obstacleGrid);
8        int left=count(i,j-1,obstacleGrid);
9        return up+left;
10    }
11    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
12        int n=obstacleGrid.size();
13        int m=obstacleGrid[0].size();
14        int cnt=count(n-1,m-1,obstacleGrid);
15        return cnt;
16    }
17};
18
19
20class Solution {
21public:
22    int count(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
23        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
24        if(i==0 && j==0) return 1;
25        if(i<0 || j<0) return 0;
26        if(dp[i][j]!=-1) return dp[i][j];
27        int up=count(i-1,j,obstacleGrid,dp);
28        int left=count(i,j-1,obstacleGrid,dp);
29        return dp[i][j]=up+left;
30    }
31    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
32        int n=obstacleGrid.size();
33        int m=obstacleGrid[0].size();
34        vector<vector<int>> dp(n,vector<int>(m,-1));
35        int cnt=count(n-1,m-1,obstacleGrid,dp);
36        return cnt;
37    }
38};