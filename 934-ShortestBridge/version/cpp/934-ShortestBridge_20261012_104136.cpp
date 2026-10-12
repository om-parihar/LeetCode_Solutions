// Last updated: 10/12/2026, 10:41:36 AM
1class Solution {
2public:
3    int shortestBridge(vector<vector<int>>& grid) {
4        int n=grid.size();
5        queue<pair<int,int>> q;
6        queue<pair<int,pair<int,int>>> temp_q;
7        for(int i=0;i<n;i++){
8            int flg=0;
9            for(int j=0;j<n;j++){
10                if(grid[i][j]==1){
11                    flg=1;
12                    q.push({i,j});
13                    temp_q.push({0,{i,j}});
14                    grid[i][j]=2;
15                    int delrow[]={0,-1,0,1};
16                    int delcol[]={-1,0,1,0};
17                    while(!q.empty()){
18                        int row=q.front().first;
19                        int col=q.front().second;
20                        q.pop();
21                        for(int a=0;a<4;a++){
22                            int nrow=row+delrow[a];
23                            int ncol=col+delcol[a];
24                            if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
25                                grid[nrow][ncol]=2;
26                                q.push({nrow,ncol});
27                                temp_q.push({0,{nrow,ncol}});
28                            }
29                        }
30                    }
31                    break;
32                }
33            }
34            if(flg==1) break;
35        }
36        while(!temp_q.empty()){
37                int dis=temp_q.front().first;
38                int row=temp_q.front().second.first;
39                int col=temp_q.front().second.second;
40                temp_q.pop();
41                int delrow[]={0,-1,0,1};
42                int delcol[]={-1,0,1,0};
43                for(int i=0;i<4;i++){
44                    int nrow=row+delrow[i];
45                    int ncol=col+delcol[i];
46                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
47                        if(grid[nrow][ncol]==1){
48                            return dis;
49                        }
50                        if(grid[nrow][ncol]==0){
51                            grid[nrow][ncol]=2;
52                            temp_q.push({dis+1,{nrow,ncol}});
53                        }
54                    }
55                }
56            }
57        return -1;
58    }
59};