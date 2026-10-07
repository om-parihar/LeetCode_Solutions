// Last updated: 10/7/2026, 9:55:11 AM
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
15        int mnr=INT_MAX;
16        int mnc=INT_MAX;
17        vector<vector<int>> vis(n,vector<int>(m,0));
18        q.push({0,{entrance[0],entrance[1]}});
19        vis[entrance[0]][entrance[1]]=1;
20        while(!q.empty()){
21            int dis=q.front().first;
22            int row=q.front().second.first;
23            int col=q.front().second.second;
24            q.pop();
25            if((row==n-1 || row==0 || col==m-1 || col==0) && (isnotentrance(row,col,entrance))){
26                return dis;
27            }
28            for(int i=0;i<4;i++){
29                int nrow=row+delrow[i];
30                int ncol=col+delcol[i];
31                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && maze[nrow][ncol]=='.' && vis[nrow][ncol]==0){
32                    vis[nrow][ncol]=1;
33                    q.push({dis+1,{nrow,ncol}});
34                }
35            }
36        }
37        return -1;
38    }
39};