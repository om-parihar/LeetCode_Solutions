// Last updated: 8/10/2026, 4:49:48 PM
1class Solution1 {
2public:
3    int count(int i, int j, vector<vector<int>> &grid){
4        if(i==0 && j==0) return grid[0][0];
5        if(i<0 || j<0) return INT_MAX;
6        int up=count(i-1,j,grid);
7        int left=count(i,j-1,grid);
8        return grid[i][j]+min(up,left);
9    }
10    int minPathSum(vector<vector<int>>& grid) {
11        int n=grid.size();
12        int m=grid[0].size();
13        int cnt=count(n-1,m-1,grid);
14        return cnt;
15    }
16};
17
18class Solution {
19public:
20    int count(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
21        if(i==0 && j==0) return grid[0][0];
22        if(i<0 || j<0) return INT_MAX;
23        if(dp[i][j]!=-1) return dp[i][j];
24        int up=count(i-1,j,grid,dp);
25        int left=count(i,j-1,grid,dp);
26        return dp[i][j]=grid[i][j]+min(up,left);
27    }
28    int minPathSum(vector<vector<int>>& grid) {
29        int n=grid.size();
30        int m=grid[0].size();
31        vector<vector<int>> dp(n,vector<int>(m,-1));
32        int cnt=count(n-1,m-1,grid,dp);
33        return cnt;
34    }
35};