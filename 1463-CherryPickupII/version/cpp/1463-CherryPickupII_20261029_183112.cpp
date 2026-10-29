// Last updated: 10/29/2026, 6:31:12 PM
1class Solution {
2public:
3    int dfs(int row,int col1,int col2, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
4        if(row==grid.size()){
5            return 0;
6        }
7        if(col1>=grid[0].size() || col2>=grid[0].size() || col1<0 || col2<0){
8            return INT_MIN;
9        }
10        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
11        int cheries;
12        if(col1==col2){
13            cheries=grid[row][col1];
14        }
15        else{
16            cheries=grid[row][col1]+grid[row][col2];
17        }
18        int maxi=INT_MIN;
19        for(int r1=-1;r1<=1;r1++){
20            for(int r2=-1;r2<=1;r2++){
21                int future=dfs(row+1,col1+r1,col2+r2,grid,dp);
22                if(future!=INT_MIN){
23                    maxi=max(maxi,future);
24                }
25            }
26        }
27        if(maxi==INT_MIN) return INT_MIN;
28        return dp[row][col1][col2] = cheries+maxi;
29        
30    }
31    int cherryPickup(vector<vector<int>>& grid) {
32         int n=grid.size();
33         int m=grid[0].size();
34         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
35         return dfs(0,0,m-1,grid,dp);
36    }
37};