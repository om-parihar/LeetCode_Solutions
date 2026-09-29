// Last updated: 9/29/2026, 4:48:40 PM
1class Solution {
2public:
3    int memo[101][101][201];
4    bool solve(int i, int j, vector<vector<char>>& grid, int lc) {
5        if(i>grid.size()-1 || j>grid[0].size()-1) return 0;
6        if(grid[i][j]=='('){
7            lc++;
8        }
9        else{
10            lc--;
11        }
12        if(lc<0) return 0;
13        if(memo[i][j][lc]!=-1) return memo[i][j][lc];
14        if(i==grid.size()-1 && j==grid[0].size()-1){
15            return lc==0;
16        }
17        int down=solve(i+1,j,grid,lc);
18        int right=solve(i,j+1,grid,lc);
19        return memo[i][j][lc] = down||right;
20    }
21    bool hasValidPath(vector<vector<char>>& grid) {
22        int m=grid.size();
23        int n=grid[0].size();
24        vector<vector<int>> dp(m,vector<int>(n,-1));
25        memset(memo, -1, sizeof(memo));
26        return solve(0,0,grid,0);
27    }
28};