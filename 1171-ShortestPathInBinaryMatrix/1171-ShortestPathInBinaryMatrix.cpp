// Last updated: 8/31/2026, 4:28:05 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({1,{0,0}});
        vis[0][0]=1;
        vector<pair<int,int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int cols=q.front().second.second;
            q.pop();
            if(row==n-1 && cols==n-1){
                return dis;
            }
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=cols+it.second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};