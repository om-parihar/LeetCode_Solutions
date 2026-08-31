// Last updated: 8/31/2026, 4:27:07 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> q;
        q.push({0,{0,0}});
        vis[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int dis=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            if(row==n-1 && col==m-1) return dis;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newdis=max(abs(heights[nrow][ncol]-heights[row][col]),dis);
                    if(newdis<vis[nrow][ncol]){
                        vis[nrow][ncol]=newdis;
                        q.push({newdis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};