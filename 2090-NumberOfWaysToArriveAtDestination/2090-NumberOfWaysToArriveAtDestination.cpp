// Last updated: 8/31/2026, 4:26:23 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> edge(n);
        for(auto it: roads){
            edge[it[0]].push_back({it[1],it[2]});
            edge[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,
                    vector<pair<long long,int>>,
                    greater<pair<long long,int>>> pq;
        vector<int> ways(n,0);
        vector<long long> vis(n,LLONG_MAX);
        pq.push({0,0});
        vis[0]=0;
        ways[0]=1;
        int MOD=(int)(1e9+7);
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis > vis[node]) continue;
            for(auto it: edge[node]){
                int n=it.first;
                int cost=it.second;
                if(cost+dis<vis[n]){
                    vis[n]=cost+dis;
                    pq.push({cost+dis,n});
                    ways[n]=ways[node];
                }
                else if(cost+dis==vis[n]){
                    ways[n]=(ways[node]+ways[n])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};