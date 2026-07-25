// Last updated: 7/25/2026, 11:02:16 PM
class Solution {
public:
    bool solve(vector<vector<char>> &board, string word,int idx, int i, int j, int n, int m){
        if(idx>=word.size()) return true;
        if(i<0 ||i>=n || j<0 || j>=m || board[i][j]=='.' || board[i][j]!=word[idx]) return false;
        if(word.size()==1 && word[idx]==board[i][j]) return true;
        board[i][j]='.';
        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        bool temp=false;
        for(int index=0;index<4;index++){
            temp=temp||solve(board,word,idx+1,i+x[index],j+y[index],n,m);
        }
        board[i][j]=word[idx];
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(solve(board,word,0,i,j,n,m)) return true;
                }
            }
        }
        return false;
    }
};