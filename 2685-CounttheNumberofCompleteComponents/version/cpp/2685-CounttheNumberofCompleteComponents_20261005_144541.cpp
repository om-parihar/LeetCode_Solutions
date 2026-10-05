// Last updated: 10/5/2026, 2:45:41 PM
1class Solution {
2public:
3    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int &degreeSum, int &nodeCount){
4        vis[i]=1;
5        nodeCount++;
6        degreeSum+=adj[i].size();
7        for(auto it: adj[i]){
8            if(!vis[it]){
9                dfs(it,adj,vis,degreeSum,nodeCount);
10            }
11        }
12    }
13    int countCompleteComponents(int n, vector<vector<int>>& edges) {
14        vector<vector<int>> adj(n);
15        for(auto it: edges){
16            int u=it[0];
17            int v=it[1];
18            adj[u].push_back(v);
19            adj[v].push_back(u);
20        }
21        vector<int> vis(n,0);
22        int cnt=0;
23        for(int i=0;i<n;i++){
24            if(!vis[i]){
25                int degreeSum=0;
26                int nodeCount=0;
27                dfs(i,adj,vis,degreeSum,nodeCount);
28                if (degreeSum == nodeCount * (nodeCount - 1)) {
29                    cnt++;
30                }
31            }
32        }
33        return cnt;
34    }
35};