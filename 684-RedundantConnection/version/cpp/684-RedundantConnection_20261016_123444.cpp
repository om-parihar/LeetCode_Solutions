// Last updated: 10/16/2026, 12:34:44 PM
1class Solution {
2public:
3    bool check(int u,int v, vector<vector<int>>& adj,vector<int> &vis){
4        if(u==v) return true;
5        vis[u]=1;
6        for(int it: adj[u]){
7            if(!vis[it] && check(it,v,adj,vis)){
8                return true;
9            }
10        }
11        return false;
12    }
13    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
14        int n=edges.size();
15        vector<vector<int>> adj(n+1);
16        for(auto it: edges){
17            int u=it[0];
18            int v=it[1];
19            vector<int> vis(n+1,0);
20            if(check(u,v,adj,vis)) return {u,v};
21            adj[u].push_back(v);
22            adj[v].push_back(u);
23        }
24        return {};
25    }
26};