// Last updated: 8/31/2026, 4:25:19 PM
class Solution {
public:
    void dfs(int k, vector<vector<int>> &edges, vector<int> &vis){
        vis[k]=1;
        for(auto it: edges[k]){
            if(!vis[it]){
                dfs(it,edges,vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<vector<int>> edges(n);
        for(auto it: invocations){
            int u = it[0];
            int v = it[1];
            edges[u].push_back(v);
        }
        vector<int> vis(n,0);
        dfs(k,edges,vis);
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }
      for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
        }
    }
    return ans;
    }
};