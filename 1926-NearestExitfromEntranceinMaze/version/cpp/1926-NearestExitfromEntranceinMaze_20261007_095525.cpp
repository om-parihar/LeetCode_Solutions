// Last updated: 10/7/2026, 9:55:25 AM
1class Solution {
2public:
3    bool isnotentrance(int i, int j,vector<int>& entrance){
4        if(i!=entrance[0] || j!=entrance[1]){
5            return true;
6        }
7        return false;
8    }
9    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
10        int n=maze.size();
11        int m=maze[0].size();
12        queue<pair<int,pair<int,int>>> q;
13        int delrow[]={0,-1,0,1};
14        int delcol[]={-1,0,1,0};
15        vector<vector<int>> vis(n,vector<int>(m,0));
16        q.push({0,{entrance[0],entrance[1]}});
17        vis[entrance[0]][entrance[1]]=1;
18        while(!q.empty()){
19            int dis=q.front().first;
20            int row=q.front().second.first;
21            int col=q.front().second.second;
22            q.pop();
23            if((row==n-1 || row==0 || col==m-1 || col==0) && (isnotentrance(row,col,entrance))){
24                return dis;
25            }
26            for(int i=0;i<4;i++){
27                int nrow=row+delrow[i];
28                int ncol=col+delcol[i];
29                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && maze[nrow][ncol]=='.' && vis[nrow][ncol]==0){
30                    vis[nrow][ncol]=1;
31                    q.push({dis+1,{nrow,ncol}});
32                }
33            }
34        }
35        return -1;
36    }
37};