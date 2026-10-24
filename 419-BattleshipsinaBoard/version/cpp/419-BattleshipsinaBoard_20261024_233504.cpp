// Last updated: 10/24/2026, 11:35:04 PM
1class Solution {
2public:
3    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
4        int n=board.size();
5        int m=board[0].size();
6        int delrow[]={0,-1,0,1};
7        int delcol[]={-1,0,1,0};
8        for(int i=0;i<4;i++){
9            int nrow=row+delrow[i];
10            int ncol=col+delcol[i];
11            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='X' && vis[nrow][ncol]==0){
12                vis[nrow][ncol]=1;
13                dfs(nrow,ncol,board,vis);
14            }
15        }
16    }
17    int countBattleships(vector<vector<char>>& board) {
18        int n=board.size();
19        int m=board[0].size();
20        vector<vector<int>> vis(n,vector<int>(m,0));
21        int cnt=0;
22        for(int i=0;i<n;i++){
23            for(int j=0;j<m;j++){
24                if(board[i][j]=='X' && vis[i][j]==0){
25                    cnt++;
26                    dfs(i,j,board,vis);
27                }
28            }
29        }
30        return cnt;
31    }
32};