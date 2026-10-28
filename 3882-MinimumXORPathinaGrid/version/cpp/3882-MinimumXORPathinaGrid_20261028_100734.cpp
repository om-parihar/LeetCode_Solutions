// Last updated: 10/28/2026, 10:07:34 AM
1class Solution1 {
2public:
3    int count(int row, int col, vector<vector<int>>& grid, int sum,int& ans){
4        if(row==grid.size()-1 && col==grid[0].size()-1){
5            sum^=grid[row][col];
6            ans=min(sum,ans);
7            return grid[row][col];
8        }
9        if(row==grid.size() || col==grid[0].size()){
10            return 0;
11        }
12        sum^=grid[row][col];
13        int down=count(row+1,col,grid,sum,ans);
14        int right=count(row,col+1,grid,sum,ans);
15        return ans;
16    }
17    int minCost(vector<vector<int>>& grid) {
18        int n=grid.size();
19        int m=grid[0].size();
20        int ans=INT_MAX;
21        count(0,0,grid,0,ans);
22        return ans;
23    }
24};
25
26class Solution {
27public:
28    bitset<1024> count(int row, int col, vector<vector<int>>& grid,
29                       vector<vector<vector<bitset<1024>>>>& dp,
30                       vector<vector<vector<bool>>>& vis) {
31        int n = grid.size(), m = grid[0].size();
32
33        if (row >= n || col >= m) return bitset<1024>();
34
35        if (vis[row][col][0]) {
36            return dp[row][col][0];
37        }
38
39        bitset<1024> ans;
40
41        if (row == n - 1 && col == m - 1) {
42            ans[grid[row][col]] = true;
43        } else {
44            auto down = count(row + 1, col, grid, dp, vis);
45            auto right = count(row, col + 1, grid, dp, vis);
46            ans = down | right;
47
48            bitset<1024> next;
49
50            for (int x = 0; x < 1024; x++) {
51                if (ans[x]) {
52                    next[x ^ grid[row][col]] = true;
53                }
54            }
55
56            ans = next;
57        }
58
59        vis[row][col][0] = true;
60        return dp[row][col][0] = ans;
61    }
62
63    int minCost(vector<vector<int>>& grid) {
64        int n = grid.size(), m = grid[0].size();
65
66        vector<vector<vector<bitset<1024>>>> dp(
67            n, vector<vector<bitset<1024>>>(m, vector<bitset<1024>>(1))
68        );
69        vector<vector<vector<bool>>> vis(
70            n, vector<vector<bool>>(m, vector<bool>(1, false))
71        );
72
73        auto possible = count(0, 0, grid, dp, vis);
74
75        for (int x = 0; x < 1024; x++) {
76            if (possible[x]) return x;
77        }
78
79        return -1;
80    }
81};