// Last updated: 11/23/2026, 10:20:58 AM
1class Solution {
2public:
3    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& vis){
4        int delrow[]={0,-1,0,1};
5        int delcol[]={-1,0,1,0};
6        int n=heights.size();
7        int m=heights[0].size();
8        vis[row][col]=1;
9        for(int i=0;i<4;i++){
10            int nrow=row+delrow[i];
11            int ncol=col+delcol[i];
12            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
13                if(heights[nrow][ncol]>=heights[row][col] && !vis[nrow][ncol]){
14                    vis[nrow][ncol]=1;
15                    dfs(nrow,ncol,heights,vis);
16                }
17            }
18        }
19    }
20    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
21        vector<vector<int>> ans;
22        int n=heights.size();
23        int m=heights[0].size();
24        vector<vector<int>> vis1(n,vector<int>(m,0));
25        vector<vector<int>> vis2(n,vector<int>(m,0));
26        for(int i=0;i<n;i++){
27            dfs(i,0,heights,vis1);
28            dfs(i,m-1,heights,vis2);
29        }
30        for(int j=0;j<m;j++){
31            dfs(0,j,heights,vis1);
32            dfs(n-1,j,heights,vis2);
33        }
34        for(int i=0;i<n;i++){
35            for(int j=0;j<m;j++){
36                if(vis1[i][j] && vis2[i][j]){
37                    ans.push_back({i,j});
38                }
39            }
40        }
41        return ans;
42    }
43};
44
45class Solution1 {
46public:
47    void dfspa(int row, int col, vector<vector<int>>& heights, int& flg2, vector<vector<int>>& vis2){
48        int delrow[]={0,-1,0,1};
49        int delcol[]={-1,0,1,0};
50        int n=heights.size();
51        int m=heights[0].size();
52        vis2[row][col]=1;
53        if(row==0 || col==0){
54            flg2=1;
55            return;
56        }
57        for(int i=0;i<4;i++){
58            int nrow=row+delrow[i];
59            int ncol=col+delcol[i];
60            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
61                if(heights[nrow][ncol]<=heights[row][col] && !vis2[nrow][ncol]){
62                    vis2[nrow][ncol]=1;
63                    dfspa(nrow,ncol,heights,flg2,vis2);
64                }
65            }
66        }
67    }
68
69    void dfsat(int row, int col, vector<vector<int>>& heights, int& flg1, vector<vector<int>>& vis1){
70        int delrow[]={0,-1,0,1};
71        int delcol[]={-1,0,1,0};
72        int n=heights.size();
73        int m=heights[0].size();
74        vis1[row][col]=1;
75        if(row==n-1 || col==m-1){
76            flg1=1;
77            return;
78        }
79        for(int i=0;i<4;i++){
80            int nrow=row+delrow[i];
81            int ncol=col+delcol[i];
82            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
83                if(heights[nrow][ncol]<=heights[row][col] && !vis1[nrow][ncol]){
84                    vis1[nrow][ncol]=1;
85                    dfsat(nrow,ncol,heights,flg1,vis1);
86                }
87            }
88        }
89    }
90    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
91        vector<vector<int>> ans;
92        int n=heights.size();
93        int m=heights[0].size();
94        for(int i=0;i<n;i++){
95            for(int j=0;j<m;j++){
96                int flg1=0;
97                int flg2=0;
98                vector<vector<int>> vis1(n,vector<int>(m,0));
99                vector<vector<int>> vis2(n,vector<int>(m,0));
100                dfsat(i,j,heights,flg1,vis1);
101                dfspa(i,j,heights,flg2,vis2);
102                if(flg1 && flg2) ans.push_back({i,j});
103            }
104        }
105        return ans;
106    }
107};