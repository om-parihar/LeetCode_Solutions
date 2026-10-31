// Last updated: 10/31/2026, 4:44:24 PM
1class Solution {
2public:
3    int MOD=1e9+7;
4    int count(string pos,int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
5        int n=grid.size();
6        int m=grid[0].size();
7        if(row>=n || col>=m) return 0;
8        if(row==n-1 && col==m-1) return 1;
9        int dir;
10        if(pos=="down") dir=1;
11        if(pos=="right") dir=0;
12        if(dp[row][col][dir]!=-1) return dp[row][col][dir];
13        int down=0;
14        int right=0;
15        int left=0;
16        int up=0;
17        if(grid[row][col]==1 && pos=="down"){
18            down=count("right",row,col+1,grid,dp);
19        }
20        else if(grid[row][col]==1 && pos=="right"){
21            right=count("down",row+1,col,grid,dp);
22        }
23        else{
24            left=count("right",row,col+1,grid,dp);
25            up=count("down",row+1,col,grid,dp);
26        }
27        return dp[row][col][dir] = (down+right+left+up)%MOD;
28    }
29    int uniquePaths(vector<vector<int>>& grid) {
30        int n=grid.size();
31        int m=grid[0].size();
32        int cnt=0;
33        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
34        return count("first",0,0,grid,dp);
35    }  
36};
37
38class Solution1 {
39public:
40    int uniquePaths(vector<vector<int>>& grid) {
41        int n=grid.size();
42        int m=grid[0].size();
43        int cnt=0;
44        int MOD=1e9+7;
45        queue<pair<string,pair<int,int>>> q;
46        q.push({"first",{0,0}});
47        while(!q.empty()){
48            int row=q.front().second.first;
49            int col=q.front().second.second;
50            string pos=q.front().first;
51            q.pop();
52            if(row>=n || col>=m) continue;
53            if(row==n-1 && col==m-1){
54                cnt=(cnt+1)%MOD;
55                continue;
56            }
57            if(grid[row][col]==1){
58                if(pos=="down"){
59                    q.push({"right",{row,col+1}});
60                }
61                else if(pos=="right"){
62                    q.push({"down",{row+1,col}});
63                }
64            }
65            else{
66                q.push({"right",{row,col+1}});
67                q.push({"down",{row+1,col}});
68            }
69        }
70        return cnt;
71    }  
72};