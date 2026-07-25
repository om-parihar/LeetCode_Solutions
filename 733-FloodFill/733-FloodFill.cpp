// Last updated: 7/25/2026, 10:58:49 PM
class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int iniColor){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,ans,image,color,iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};