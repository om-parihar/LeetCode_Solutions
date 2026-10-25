// Last updated: 10/25/2026, 11:07:51 AM
1class Solution {
2public:
3    void dfss(int row, int col, vector<vector<int>>& grid){
4        int n=grid.size();
5        int m=grid[0].size();
6        int delrow[]={0,-1,0,1};
7        int delcol[]={-1,0,1,0};
8        for(int i=0;i<4;i++){
9            int nrow=row+delrow[i];
10            int ncol=col+delcol[i];
11            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==0){
12                grid[nrow][ncol]=1;
13                dfss(nrow,ncol,grid);
14            }
15        }
16    }
17    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
18        int n=grid.size();
19        int m=grid[0].size();
20        int delrow[]={0,-1,0,1};
21        int delcol[]={-1,0,1,0};
22        for(int i=0;i<4;i++){
23            int nrow=row+delrow[i];
24            int ncol=col+delcol[i];
25            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
26                vis[nrow][ncol]=1;
27                dfs(nrow,ncol,grid,vis);
28            }
29        }
30    }
31    int closedIsland(vector<vector<int>>& grid) {
32        int n=grid.size();
33        int m=grid[0].size();
34        vector<vector<int>> vis(n,vector<int>(m,0));
35        int cnt=0;
36        for(int i=0;i<n;i++){
37            if(grid[i][0]==0){
38                grid[i][0]=1;
39                dfss(i,0,grid);
40            }
41        }
42        for(int i=0;i<m;i++){
43            if(grid[0][i]==0){
44                grid[0][i]=1;
45                dfss(0,i,grid);
46            }
47        }
48        for(int i=0;i<m;i++){
49            if(grid[n-1][i]==0){
50                grid[n-1][i]=1;
51                dfss(n-1,i,grid);
52            }
53        }
54        for(int i=0;i<n;i++){
55            if(grid[i][m-1]==0){
56                grid[i][m-1]=1;
57                dfss(i,m-1,grid);
58            }
59        }
60        for(int i=0;i<n;i++){
61            for(int j=0;j<m;j++){
62                if(grid[i][j]==0 && vis[i][j]==0){
63                    cnt++;
64                    vis[i][j]=1;
65                    dfs(i,j,grid,vis);
66                }
67            }
68        }
69        return cnt;
70    }
71};