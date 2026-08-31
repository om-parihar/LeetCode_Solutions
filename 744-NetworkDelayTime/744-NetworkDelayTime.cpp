// Last updated: 8/31/2026, 4:29:36 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> edge(n+1);
        vector<int> vis(n+1,1e7);
        for(auto it: times) {
            edge[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>> q;
        q.push({0,k});
        vis[k]=0;
        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto it: edge[node]){
                int n=it.first;
                int d=it.second;
                if(d+dis<vis[n]){
                    vis[n]=d+dis;
                    q.push({d+dis,n});
                }
            }
        }
        int mx=*max_element(vis.begin()+1,vis.end());
        if(mx==1e7) return -1;
        return mx;
    }
};