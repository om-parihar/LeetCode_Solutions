// Last updated: 7/25/2026, 10:56:48 PM
class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                dfs(adj[node][j],adj,visited);
            }
        }
    } 

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,0);
        dfs(source,adj,visited);
        return visited[destination];
    }
};