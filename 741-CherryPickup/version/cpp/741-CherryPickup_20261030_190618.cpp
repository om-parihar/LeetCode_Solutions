// Last updated: 10/30/2026, 7:06:18 PM
1class Solution {
2public:
3    int count(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
4        int n=grid.size();
5        int c2 = r1 + c1 - r2;
6        if(r1<0 || r2<0 || c1<0 || c2<0 || r1>=n || r2>=n || c1>=n || c2>=n){
7            return INT_MIN;
8        }
9        if(grid[r1][c1]==-1 || grid[r2][c2]==-1){
10            return INT_MIN;
11        }
12        if(r1==n-1 && c1==n-1){
13            return grid[r1][c1];
14        }
15        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
16        int cheries=grid[r1][c1];
17        if(r1!=r2 || c1!=c2){
18            cheries+=grid[r2][c2];
19        }
20        int best=0;
21        int a=count(r1,c1+1,r2,grid,dp);
22        int b=count(r1,c1+1,r2+1,grid,dp);
23        int c=count(r1+1,c1,r2,grid,dp);
24        int d=count(r1+1,c1,r2+1,grid,dp);
25        best=max({a,b,c,d});
26        if(best<0){
27            return dp[r1][c1][r2]=INT_MIN;
28        }
29        return dp[r1][c1][r2] = cheries+best;
30    }
31    int cherryPickup(vector<vector<int>>& grid) {
32        int n =grid.size();
33        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
34        int ans=count(0,0,0,grid,dp);
35        return max(0,ans);
36    }
37};