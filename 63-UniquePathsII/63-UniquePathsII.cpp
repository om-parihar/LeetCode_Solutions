// Last updated: 8/10/2026, 4:28:53 PM
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
20class Solution2 {
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
39
40
41class Solution {
42public:
43    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
44        int n=obstacleGrid.size();
45        int m=obstacleGrid[0].size();
46        vector<vector<int>> dp(n,vector<int>(m,-1));
47        dp[0][0]=1;
48        for(int i=0;i<n;i++){
49            for(int j=0;j<m;j++){
50                if(obstacleGrid[i][j]==1){
51                    dp[i][j]=0;
52                    continue;
53                }
54                if(i==0 && j==0){
55                    dp[i][j]=1;
56                    continue;
57                }    
58                int up=0,left=0;
59                if(i>0) up=dp[i-1][j];
60                if(j>0) left=dp[i][j-1];
61                dp[i][j]=up+left;
62            }
63        }
64        return dp[n-1][m-1];
65    }
66};