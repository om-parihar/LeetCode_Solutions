// Last updated: 7/25/2026, 11:00:49 PM
class Solution {
private:
    bool detect(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;
        for(auto adjacentNode: adj[node]){
            if(vis[adjacentNode]==1){
                return true;
            }
            if(vis[adjacentNode]==0){
                if(detect(adjacentNode,adj,vis)){
                    return true;
                }
            }
        }
        vis[node]=2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return false;
                }
            }
        }
        return true;
    }
};