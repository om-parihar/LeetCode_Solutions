// Last updated: 7/25/2026, 10:57:03 PM
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans(n+2,0);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            ans[u]++;
            ans[v]++;
        }
        for(int i=1;i<=n+1;i++){
            if(ans[i]==n){
                return i;
            }
        }
        return -1;
    }
};