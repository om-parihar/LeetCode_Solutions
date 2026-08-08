// Last updated: 8/8/2026, 10:39:36 AM
1class Solution {
2public:
3    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
4        vector<vector<pair<int,int>>> edge(n);
5        for(auto it: edges) {
6            edge[it[0]].push_back({it[1],it[2]});
7            edge[it[1]].push_back({it[0],it[2]});
8        }
9        int ans=-1;
10        int minCount=INT_MAX;
11        for(int src=0;src<n;src++){
12            vector<int> dist(n,1e7);
13            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
14            pq.push({0,src});
15            dist[src]=0;
16            while(!pq.empty()){
17                int dis=pq.top().first;
18                int node=pq.top().second;
19                pq.pop();
20                if(dis>dist[node]) continue;
21                for(auto it: edge[node]) {
22                    int adjnode=it.first;
23                    int adjdis=it.second;
24                    if(adjdis+dis<dist[adjnode]){
25                        dist[adjnode]=adjdis+dis;
26                        pq.push({dist[adjnode],adjnode});
27                    }
28                }
29            }
30            int cnt=0;
31            for(int i = 0; i < n; i++){
32            if(i != src && dist[i] <= distanceThreshold){
33                cnt++;
34            }
35        }
36            if(cnt<=minCount){
37                minCount=cnt;
38                ans=src;
39            }
40        }
41        return ans;
42    }
43};