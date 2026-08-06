// Last updated: 8/6/2026, 12:24:50 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<vector<pair<int,int>>> edges(n);
5        for(auto it:flights){
6            edges[it[0]].push_back({it[1],it[2]});
7        }
8        vector<vector<int>> vis(n, vector<int>(k + 2, 1e9));
9        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
10        pq.push({0,{src,0}});
11        vis[src][0]=0;
12        while(!pq.empty()){
13            int wt=pq.top().first;
14            int node=pq.top().second.first;
15            int dis=pq.top().second.second;
16            pq.pop();
17            if(dis==k+1) continue;
18            for(auto i: edges[node]){
19                int adjnode=i.first;
20                int adjwt=i.second;
21                if(dis <= k && wt + adjwt < vis[adjnode][dis+1]){
22                    vis[adjnode][dis+1] = wt + adjwt;
23                    pq.push({wt+adjwt, {adjnode,dis+1}});
24                }
25            }
26        }
27        int ans = 1e9;
28        for (int i = 0; i <= k + 1; i++) {
29            ans = min(ans, vis[dst][i]);
30        }
31        return (ans == 1e9) ? -1 : ans;
32    }
33};