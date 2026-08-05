// Last updated: 8/5/2026, 12:56:20 PM
1class Solution {
2public:
3    void dfs(int k, vector<vector<int>> &edges, vector<int> &vis){
4        vis[k]=1;
5        for(auto it: edges[k]){
6            if(!vis[it]){
7                dfs(it,edges,vis);
8            }
9        }
10    }
11
12    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
13        vector<int> ans;
14        vector<vector<int>> edges(n);
15        for(auto it: invocations){
16            int u = it[0];
17            int v = it[1];
18            edges[u].push_back(v);
19        }
20        vector<int> vis(n,0);
21        dfs(k,edges,vis);
22        for (auto &it : invocations) {
23            int u = it[0];
24            int v = it[1];
25
26            if (!vis[u] && vis[v]) {
27                vector<int> ans;
28                for (int i = 0; i < n; i++) {
29                    ans.push_back(i);
30                }
31                return ans;
32            }
33        }
34      for (int i = 0; i < n; i++) {
35        if (!vis[i]) {
36            ans.push_back(i);
37        }
38    }
39    return ans;
40    }
41};