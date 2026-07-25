// Last updated: 7/25/2026, 11:01:35 PM
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
         vector<vector<int>>& vis) {

    int n = board.size();
    int m = board[0].size();

    if(row < 0 || row >= n || col < 0 || col >= m)
        return;

    if(vis[row][col] || board[row][col] == 'X')
        return;

    vis[row][col] = 1;

    dfs(row-1, col, board, vis);
    dfs(row+1, col, board, vis);
    dfs(row, col-1, board, vis);
    dfs(row, col+1, board, vis);
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0, i, board, vis);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(n-1, i, board, vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i, 0, board, vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i, m-1, board, vis);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                board[i][j] = 'X';
                }
            }
        }
    }
};