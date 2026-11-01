// Last updated: 11/1/2026, 4:25:23 PM
1class Solution {
2public:
3    int n;
4    int delrow[4] = {-1, 0, 1, 0};
5    int delcol[4] = {0, 1, 0, -1};
6
7    int dfs(int row, int col, int id, vector<vector<int>>& grid) {
8        grid[row][col] = id;
9        int cnt = 1;
10
11        for(int i = 0; i < 4; i++) {
12            int nrow = row + delrow[i];
13            int ncol = col + delcol[i];
14
15            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
16               grid[nrow][ncol] == 1) {
17                cnt += dfs(nrow, ncol, id, grid);
18            }
19        }
20
21        return cnt;
22    }
23
24    int largestIsland(vector<vector<int>>& grid) {
25        n = grid.size();
26
27        unordered_map<int, int> area;
28        int id = 2;
29        int ans = 0;
30
31        for(int i = 0; i < n; i++) {
32            for(int j = 0; j < n; j++) {
33                if(grid[i][j] == 1) {
34                    int cnt = dfs(i, j, id, grid);
35                    area[id] = cnt;
36                    ans = max(ans, cnt);
37                    id++;
38                }
39            }
40        }
41
42        for(int i = 0; i < n; i++) {
43            for(int j = 0; j < n; j++) {
44                if(grid[i][j] == 0) {
45                    unordered_set<int> st;
46
47                    for(int k = 0; k < 4; k++) {
48                        int nrow = i + delrow[k];
49                        int ncol = j + delcol[k];
50
51                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
52                            if(grid[nrow][ncol] > 1) {
53                                st.insert(grid[nrow][ncol]);
54                            }
55                        }
56                    }
57
58                    int cnt = 1;
59
60                    for(auto x : st) {
61                        cnt += area[x];
62                    }
63
64                    ans = max(ans, cnt);
65                }
66            }
67        }
68
69        return ans;
70    }
71};