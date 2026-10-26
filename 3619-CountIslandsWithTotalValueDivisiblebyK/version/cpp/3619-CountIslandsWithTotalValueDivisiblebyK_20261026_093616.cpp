// Last updated: 10/26/2026, 9:36:16 AM
1class Solution {
2public:
3    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, long long& sum){
4        int n=grid.size();
5        int m=grid[0].size();
6        int delrow[]={0,-1,0,1};
7        int delcol[]={-1,0,1,0};
8        for(int i=0;i<4;i++){
9            int nrow=row+delrow[i];
10            int ncol=col+delcol[i];
11            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]!=0 && vis[nrow][ncol]==0){
12                vis[nrow][ncol]=1;
13                dfs(nrow,ncol,grid,vis,sum);
14                sum+=grid[nrow][ncol];
15            }
16        }
17    }
18    int countIslands(vector<vector<int>>& grid, int k) {
19        int n=grid.size();
20        int m=grid[0].size();
21        vector<vector<int>> vis(n,vector<int>(m,0));
22        int cnt=0;
23        for(int i=0;i<n;i++){
24            for(int j=0;j<m;j++){
25                if(grid[i][j]!=0 && vis[i][j]==0){
26                    long long sum=0;
27                    sum+=grid[i][j];
28                    vis[i][j]=1;
29                    dfs(i,j,grid,vis,sum);
30                    if(sum%k==0) cnt++;
31                }
32            }
33        }
34        return cnt;
35    }
36};