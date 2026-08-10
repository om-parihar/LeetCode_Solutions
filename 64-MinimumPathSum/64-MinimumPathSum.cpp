// Last updated: 8/10/2026, 4:54:31 PM
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
18class Solution2 {
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
36
37
38
39class Solution {
40public:
41    int minPathSum(vector<vector<int>>& grid) {
42        int n=grid.size();
43        int m=grid[0].size();
44        vector<vector<int>> dp(n,vector<int>(m,-1));
45        for(int i=0;i<n;i++){
46            for(int j=0;j<m;j++){
47                if(i==0 && j==0){
48                    dp[i][j]=grid[i][j];
49                    continue;
50                }
51                int up=1e9,left=1e9;
52                if(i>0) up=dp[i-1][j];
53                if(j>0) left=dp[i][j-1];
54                dp[i][j]=grid[i][j]+min(up,left);
55            }
56        }
57        return dp[n-1][m-1];
58    }
59};