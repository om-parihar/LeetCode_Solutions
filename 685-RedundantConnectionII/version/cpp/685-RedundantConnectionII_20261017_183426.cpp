// Last updated: 10/17/2026, 6:34:26 PM
1class Solution {
2public:
3    bool dfs(int curr, int target, vector<int>& vis, const vector<vector<int>>& adj) {
4        if (curr == target) return true;
5        
6        vis[curr] = 1;
7        for (int it : adj[curr]) {
8            if (!vis[it]) {
9                if (dfs(it, target, vis, adj)) return true;
10            }
11        }
12        return false;
13    }
14
15    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
16        int n = edges.size();
17        vector<int> parent(n + 1, 0);
18        vector<int> cand1, cand2;
19
20        for (const auto& edge : edges) {
21            int u = edge[0];
22            int v = edge[1];
23            if (parent[v] != 0) {
24                cand1 = {parent[v], v};
25                cand2 = {u, v};
26                break;
27            }
28            parent[v] = u;
29        }
30
31        vector<vector<int>> adj(n + 1);
32        
33        for (const auto& edge : edges) {
34            if (!cand2.empty() && edge == cand2) continue;
35
36            int u = edge[0];
37            int v = edge[1];
38
39            vector<int> vis(n + 1, 0);
40            if (dfs(v, u, vis, adj)) {
41                if (!cand1.empty()) return cand1;
42                return {u, v};
43            }
44
45            adj[u].push_back(v);
46        }
47
48        return cand2;
49    }
50};