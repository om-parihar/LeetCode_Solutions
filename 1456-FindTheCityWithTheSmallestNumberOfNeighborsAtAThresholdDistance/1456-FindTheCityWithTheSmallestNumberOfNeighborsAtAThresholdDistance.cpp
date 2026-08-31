// Last updated: 8/31/2026, 4:27:35 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> edge(n);
        for(auto it: edges) {
            edge[it[0]].push_back({it[1],it[2]});
            edge[it[1]].push_back({it[0],it[2]});
        }
        int ans=-1;
        int minCount=INT_MAX;
        for(int src=0;src<n;src++){
            vector<int> dist(n,1e7);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            dist[src]=0;
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(dis>dist[node]) continue;
                for(auto it: edge[node]) {
                    int adjnode=it.first;
                    int adjdis=it.second;
                    if(adjdis+dis<dist[adjnode]){
                        dist[adjnode]=adjdis+dis;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
            int cnt=0;
            for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= distanceThreshold){
                cnt++;
            }
        }
            if(cnt<=minCount){
                minCount=cnt;
                ans=src;
            }
        }
        return ans;
    }
};