// Last updated: 7/25/2026, 10:56:29 PM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row;
        int mx=-1;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(auto it:mat[i]){
                if(it==1){
                    cnt++;
                }
            }
            if(cnt>mx){
                row=i;
                mx=cnt;
            }
        }
        return {row,mx};
    }
};