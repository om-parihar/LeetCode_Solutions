// Last updated: 7/25/2026, 10:57:31 PM
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int a=1;a<=k;a++){
        vector<vector<int>> arr=grid;   
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==m-1 && j==n-1){
                        arr[0][0]=grid[i][j];
                    }
                    else if(j==n-1){
                        arr[i+1][0]=grid[i][j];
                    }
                    else{
                        arr[i][j+1]=grid[i][j];
                    }
                }
            }
            grid=arr;
        }
        return grid;
    }
};