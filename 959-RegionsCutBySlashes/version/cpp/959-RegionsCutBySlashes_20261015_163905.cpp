// Last updated: 10/15/2026, 4:39:05 PM
1class Solution {
2public:
3    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& mat) {
4        int n = mat.size();
5
6        if (i < 0 || j < 0 || i >= n || j >= n ||
7            mat[i][j] == 1 || visited[i][j] == 1) {
8            return;
9        }
10
11        visited[i][j] = 1;
12
13        dfs(i + 1, j, visited, mat);
14        dfs(i - 1, j, visited, mat);
15        dfs(i, j + 1, visited, mat);
16        dfs(i, j - 1, visited, mat);
17    }
18    int regionsBySlashes(vector<string>& grid) {
19        int n=grid.size();
20        vector<vector<int>> mat(3*n, vector<int>(3*n, 0));      
21        vector<vector<int>> visited(3*n,vector<int>(3*n,0));
22        for (int i = 0; i < n; i++) {
23            for (int j = 0; j < n; j++) {
24                int r = 3 * i;
25                int c = 3 * j;
26
27                if (grid[i][j] == '/') {
28                    mat[r][c + 2] = 1;
29                    visited[r][c + 2] = 1;
30                    mat[r + 1][c + 1] = 1;
31                    visited[r + 1][c + 1] = 1;
32                    mat[r + 2][c] = 1;
33                    visited[r + 2][c] = 1;
34                }
35                else if (grid[i][j] == '\\') {
36                    mat[r][c] = 1;
37                    visited[r][c] = 1;
38                    mat[r + 1][c + 1] = 1;
39                    visited[r + 1][c + 1] = 1;
40                    mat[r + 2][c + 2] = 1;
41                    visited[r + 2][c + 2] = 1;
42                }
43            }
44        }
45        int reg=0;
46        for(int i=0;i<mat.size();i++){
47            for(int j=0;j<mat.size();j++){
48                if(visited[i][j]==0){
49                    reg++;
50                    dfs(i,j,visited,mat);
51                }
52            }
53        }
54        return reg;
55    }
56};