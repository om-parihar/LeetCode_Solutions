// Last updated: 10/21/2026, 9:39:07 AM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6        queue<pair<pair<int,int>,int>> q;
7        vector<vector<int>> vis(m,vector<int>(n,0));
8        for(int i=0;i<m;i++){
9            for(int j=0;j<n;j++){
10                if(grid[i][j]==2){
11                    q.push({{i,j},0});
12                    vis[i][j]=2;
13                }
14            }
15        }
16        int tm=0;
17        int delrow[]={0,-1,0,1};
18        int delcol[]={-1,0,1,0};
19        while(!q.empty()){
20            int row=q.front().first.first;
21            int col=q.front().first.second;
22            int dis=q.front().second;
23            tm=max(tm,dis);
24            q.pop();
25            for(int i=0;i<4;i++){
26                int nrow=row+delrow[i];
27                int ncol=col+delcol[i];
28                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
29                    vis[nrow][ncol]=2;
30                    q.push({{nrow,ncol},dis+1});
31                }
32            }
33        }
34        for(int i=0;i<m;i++){
35            for(int j=0;j<n;j++){
36                if(vis[i][j]!=2 && grid[i][j]==1){
37                    return -1;
38                }
39            }
40        }
41        return tm;
42    }
43};