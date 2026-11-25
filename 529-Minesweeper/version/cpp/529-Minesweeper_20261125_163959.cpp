// Last updated: 11/25/2026, 4:39:59 PM
1class Solution {
2public:
3    void dfs(int row, int col, vector<vector<char>>& board){
4        int delrow[]={0,-1,-1,-1,0,1,1,1};
5        int delcol[]={-1,-1,0,1,1,1,0,-1};
6        int n=board.size();
7        int m=board[0].size();
8        int cnt=0;
9        for(int i=0;i<8;i++){
10            int nrow=row+delrow[i];
11            int ncol=col+delcol[i];
12            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
13               if(board[nrow][ncol]=='M'){
14                cnt++;
15               }
16            }
17        }
18        if(cnt > 0) {
19            board[row][col] = '0' + cnt;
20            return;
21        }
22        board[row][col]='B';
23        for(int i=0;i<8;i++){
24            int nrow=row+delrow[i];
25            int ncol=col+delcol[i];
26            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
27                if(board[nrow][ncol]=='E'){
28                    dfs(nrow,ncol,board);
29                }
30            }
31        }
32    }
33    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
34        vector<vector<char>> ans;
35        int n=board.size();
36        int m=board[0].size();
37        if(board[click[0]][click[1]]=='M'){
38            board[click[0]][click[1]]='X';
39            return board;
40        }
41        dfs(click[0],click[1],board);
42        ans=board;
43        return ans;
44    }
45};