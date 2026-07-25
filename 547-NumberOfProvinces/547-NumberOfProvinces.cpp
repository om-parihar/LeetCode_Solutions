// Last updated: 7/25/2026, 10:59:11 PM
class Solution {
private:
    void DFS(int node, vector<vector<int>> &adj,vector<bool> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                DFS(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(v,0);
        int provi=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                provi++;
                DFS(i,adj,vis);
            }
        }
        return provi;
    } 
};