// Last updated: 8/5/2026, 9:51:19 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int n=grid.size();
5        queue<pair<int,pair<int,int>>> q;
6        if(grid[0][0] || grid[n-1][n-1]) return -1;
7        vector<vector<int>> vis(n,vector<int>(n,0));
8        q.push({1,{0,0}});
9        vis[0][0]=1;
10        vector<pair<int,int>> dir = {
11            {-1,-1},{-1,0},{-1,1},
12            {0,-1},        {0,1},
13            {1,-1},{1,0},{1,1}
14        };
15        while(!q.empty()){
16            int dis=q.front().first;
17            int row=q.front().second.first;
18            int cols=q.front().second.second;
19            q.pop();
20            if(row==n-1 && cols==n-1){
21                return dis;
22            }
23            for(auto it:dir){
24                int nrow=row+it.first;
25                int ncol=cols+it.second;
26                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==0){
27                    vis[nrow][ncol]=1;
28                    q.push({dis+1,{nrow,ncol}});
29                }
30            }
31        }
32        return -1;
33    }
34};