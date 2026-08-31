// Last updated: 8/31/2026, 4:29:16 PM
class Solution1 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> edges(n);
        for(auto it:flights){
            edges[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> vis(n, vector<int>(k + 2, 1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vis[src][0]=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second.first;
            int dis=pq.top().second.second;
            pq.pop();
            if(dis==k+1) continue;
            for(auto i: edges[node]){
                int adjnode=i.first;
                int adjwt=i.second;
                if(dis <= k && wt + adjwt < vis[adjnode][dis+1]){
                    vis[adjnode][dis+1] = wt + adjwt;
                    pq.push({wt+adjwt, {adjnode,dis+1}});
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= k + 1; i++) {
            ans = min(ans, vis[dst][i]);
        }
        return (ans == 1e9) ? -1 : ans;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> edges(n);
        for(auto it : flights) {
            edges[it[0]].push_back({it[1],it[2]});
        }
        vector<int> vis(n,1e7);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vis[src]=0;
        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(dis>k) continue;
            for(auto it: edges[node]){
                int adjnode=it.first;
                int adjcost=it.second;
                if(cost+adjcost<vis[adjnode]){
                    vis[adjnode]=cost+adjcost;
                    q.push({dis+1,{adjnode,cost+adjcost}});
                }
            }
        }
        return (vis[dst]==1e7)? -1: vis[dst];
    }
};