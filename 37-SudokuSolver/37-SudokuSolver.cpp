// Last updated: 8/21/2026, 2:33:26 PM
1class Solution {
2public:
3    bool isValid(int i, int j, char digits, vector<vector<char>>& board){
4        for(int a=0;a<9;a++){
5            if(board[a][j]==digits){
6                return false;
7            }
8        }
9        for(int b=0;b<9;b++){
10            if(board[i][b]==digits){
11                return false;
12            }
13        }
14        int startRow = (i / 3) * 3;
15        int startCol = (j / 3) * 3;
16
17        for(int row = startRow; row < startRow + 3; row++) {
18            for(int col = startCol; col < startCol + 3; col++) {
19                if(board[row][col] == digits)
20                    return false;
21            }
22        }
23        return true;
24    }
25    bool solve(vector<vector<char>>& board){
26        for(int i=0;i<9;i++){
27            for(int j=0;j<9;j++){
28                if(board[i][j]=='.'){
29                    for(char digits='1';digits<='9';digits++){
30                        if(isValid(i,j,digits,board)){
31                            board[i][j]=digits;
32                            if(solve(board)){
33                                return true;
34                            }
35                            board[i][j]='.';
36                        }
37                    }
38                    return false;
39                }
40            }
41        }
42        return true;
43    }
44    void solveSudoku(vector<vector<char>>& board) {
45        solve(board);
46    }
47};