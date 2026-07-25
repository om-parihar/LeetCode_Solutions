// Last updated: 7/25/2026, 11:02:24 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<vector<int>> matrixx;
        matrixx=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrixx[i][j]==0){
                    for(int k=0;k<m;k++){
                        matrix[i][k]=0;
                    }
                    for(int l=0;l<n;l++){
                        matrix[l][j]=0;
                    }
                }
            }
        }
    }
};