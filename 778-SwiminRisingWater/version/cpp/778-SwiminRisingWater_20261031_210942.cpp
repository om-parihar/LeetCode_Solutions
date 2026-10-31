// Last updated: 10/31/2026, 9:09:42 PM
1class Solution {
2public:
3    int swimInWater(vector<vector<int>>& grid) {
4        int n=grid.size();
5        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
6        vector<vector<int>> vis(n,vector<int>(n,0));
7        pq.push({grid[0][0],{0,0}});
8        int ans=INT_MAX;
9        vis[0][0]=1;
10        while(!pq.empty()){
11            int row=pq.top().second.first;
12            int col=pq.top().second.second;
13            int dis=pq.top().first;
14            pq.pop();
15            if(row>=n || col>=n) continue;
16            if(row==n-1 && col==n-1){
17                ans=min(ans,max(dis,grid[row][col]));
18                return ans;
19            }
20            int delrow[4]={0,-1,0,1};
21            int delcol[4]={-1,0,1,0};
22            for(int i=0;i<4;i++){
23                int nrow=row+delrow[i];
24                int ncol=col+delcol[i];
25                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && vis[nrow][ncol]==0){
26                    vis[nrow][ncol]=1;
27                    pq.push({(max(dis,grid[nrow][ncol])),{nrow,ncol}});
28                }
29            }
30        }
31        return -1;
32    }
33};