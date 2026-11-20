// Last updated: 11/20/2026, 7:14:16 PM
1class Solution {
2public:
3    void gameOfLife(vector<vector<int>>& board) {
4        int n=board.size();
5        int m=board[0].size();
6        vector<vector<int>> grid=board;
7        int delrow[]={0,-1,-1,-1,0,1,1,1};
8        int delcol[]={-1,-1,0,1,1,1,0,-1};
9        for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                int cn1=0;
12                int cn2=0;
13                for(int a=0;a<8;a++){
14                    int nrow=i+delrow[a];
15                    int ncol=j+delcol[a];
16                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
17                        if(board[nrow][ncol]==1){
18                            cn1++;
19                        }
20                        else{
21                            cn2++;
22                        }
23                    }
24                }
25                if(board[i][j]==1){
26                    if(cn1<2){
27                        grid[i][j]=0;
28                    }
29                    else if(cn1==2 || cn1==3){
30                        grid[i][j]=1;
31                    }
32                    else if(cn1>3){
33                        grid[i][j]=0;
34                    }
35                }
36                else{
37                    if(cn1==3){
38                        grid[i][j]=1;
39                    }
40                }
41            }
42        }
43        board=grid;
44    }
45};