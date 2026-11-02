// Last updated: 11/2/2026, 7:00:41 PM
1class Solution {
2public:
3    int count(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
4        int delrow[4]={0,-1,0,1};
5        int delcol[4]={-1,0,1,0};
6        int ways=0;
7        if(grid[i][j]==-1) return 0;
8        if(grid[i][j]==2){
9            for(int a=0;a<grid.size();a++){
10                for(int b=0;b<grid[0].size();b++){
11                    if(grid[a][b]!=-1 && vis[a][b]==0){
12                        return 0;
13                    }
14                }
15            }
16            return 1;
17        }
18        for(int a=0;a<4;a++){
19            int nrow=i+delrow[a];
20            int ncol=j+delcol[a];
21            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && vis[nrow][ncol]==0 && (grid[nrow][ncol]==0 || grid[nrow][ncol]==2)){
22                vis[nrow][ncol]=1;
23                ways+=count(nrow,ncol,grid,vis);
24                vis[nrow][ncol]=0;
25            }
26        }
27        return ways;
28    }
29    int uniquePathsIII(vector<vector<int>>& grid) {
30        int n =grid.size();
31        int m =grid[0].size();
32        int ans=0;
33        vector<vector<int>> vis(n,vector<int>(m,0));
34        for(int i=0;i<n;i++){
35            for(int j=0;j<m;j++){
36                if(grid[i][j]==1){
37                    vis[i][j]=1;
38                    ans+=count(i,j,grid,vis);
39                }
40            }
41        }
42        return ans;
43    }
44};