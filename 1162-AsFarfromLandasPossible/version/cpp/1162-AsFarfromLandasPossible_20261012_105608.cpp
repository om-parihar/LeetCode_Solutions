// Last updated: 10/12/2026, 10:56:08 AM
1class Solution {
2public:
3    int maxDistance(vector<vector<int>>& grid) {
4        int n=grid.size();
5        queue<pair<int,pair<int,int>>> q;
6        for(int i = 0; i < n; i++) {
7            for(int j = 0; j < n; j++) {
8                if(grid[i][j] == 1) {
9                    q.push({0, {i, j}});
10                }
11            }
12        }
13
14        if(q.empty() || q.size() == n * n) return -1;
15        if(q.empty()) return -1;
16        int delrow[]={0,-1,0,1};
17        int delcol[]={-1,0,1,0};
18        int max_dis=-1;
19        while(!q.empty()){
20            int row=q.front().second.first;
21            int col=q.front().second.second;
22            int dis=q.front().first;
23            q.pop();
24            for(int i=0;i<4;i++){
25                int nrow=row+delrow[i];
26                int ncol=col+delcol[i];
27                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
28                    if(grid[nrow][ncol] == 0) {
29                        grid[nrow][ncol] = 2;
30                        int next_dis = dis + 1;
31                        max_dis = max(max_dis, next_dis);
32                        q.push({next_dis, {nrow, ncol}});
33                    }
34                }
35            }
36        }
37        return max_dis;
38    }
39};