// Last updated: 9/28/2026, 10:37:57 AM
1class Solution {
2public:
3    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
4        vis[node]=1;
5        for(int neigh: adj[node]){
6            if(!vis[neigh]){
7                dfs(neigh,vis,adj);
8            }
9        }
10    }
11    int makeConnected(int n, vector<vector<int>>& connections) {
12        int v = connections.size();
13        if(v<n-1) return -1;
14        vector<vector<int>> adj(n);
15        for(int i=0;i<v;i++){
16            int u=connections[i][0];
17            int w=connections[i][1];
18            adj[u].push_back(w);
19            adj[w].push_back(u);
20        }
21        vector<int> vis(n,0);
22        int component=0;
23        for(int i=0;i<n;i++){
24            if(!vis[i]){
25                component++;
26                dfs(i,vis,adj);
27            }
28        }
29        return component-1;
30    }
31};