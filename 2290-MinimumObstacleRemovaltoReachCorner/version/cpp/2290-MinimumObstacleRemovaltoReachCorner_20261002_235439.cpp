// Last updated: 10/2/2026, 11:54:39 PM
1class Solution {
2public:
3    int minimumObstacles(vector<vector<int>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
7        q.push({0,{0,0}});
8        int delrow[]={0,-1,0,1};
9        int delcol[]={-1,0,1,0};
10        vector<vector<int>> vis(m,vector<int>(n,INT_MAX));
11        while(!q.empty()){
12            int obs=q.top().first;
13            int row=q.top().second.first;
14            int col=q.top().second.second;
15            if(row==m-1 && col==n-1) return obs;
16            if (obs > vis[row][col]) continue;
17            q.pop();
18            for(int i=0;i<4;i++){
19                int nrow=row+delrow[i];
20                int ncol=col+delcol[i];
21                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
22                    int next_obs = obs + grid[nrow][ncol];
23
24                    if (next_obs < vis[nrow][ncol]) {
25                        vis[nrow][ncol] = next_obs;
26                        q.push({next_obs, {nrow, ncol}});
27                    }
28                }
29            }
30        }
31        return vis[m-1][n-1];
32    }
33};