// Last updated: 11/19/2026, 6:00:29 PM
1class Solution1 {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<pair<int,int>>> edge(n+1);
5        vector<int> vis(n+1,1e7);
6        for(auto it: times) {
7            edge[it[0]].push_back({it[1],it[2]});
8        }
9        queue<pair<int,int>> q;
10        q.push({0,k});
11        vis[k]=0;
12        while(!q.empty()){
13            int dis=q.front().first;
14            int node=q.front().second;
15            q.pop();
16            for(auto it: edge[node]){
17                int n=it.first;
18                int d=it.second;
19                if(d+dis<vis[n]){
20                    vis[n]=d+dis;
21                    q.push({d+dis,n});
22                }
23            }
24        }
25        int mx=*max_element(vis.begin()+1,vis.end());
26        if(mx==1e7) return -1;
27        return mx;
28    }
29};
30
31class Solution2 {
32public:
33    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
34        vector<vector<pair<int,int>>> adj(n+1);
35        for(auto x:times){
36            int u=x[0];
37            int v=x[1];
38            int w=x[2];
39            adj[u].push_back({v,w});
40        }
41        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
42        vector<int> dis(n+1,INT_MAX);
43        dis[k]=0;
44        pq.push({0,k});
45        while(!pq.empty()){
46            int time=pq.top().first;
47            int node=pq.top().second;
48            pq.pop();
49            if(time>dis[node]) continue;
50            for(auto i:adj[node]){
51                int adjnode=i.first;
52                int weight=i.second;
53                if(time+weight<dis[adjnode]){
54                    dis[adjnode]=time+weight;
55                    pq.push({time+weight,adjnode});
56                }
57            }
58        }
59        int mx=*max_element(dis.begin()+1,dis.end());
60        if(mx==INT_MAX) return -1;
61        return mx;
62    }
63};
64
65// Bellman Ford
66class Solution {
67public:
68    int networkDelayTime(vector<vector<int>>& times, int n, int k){
69        vector<int> dis(n+1,INT_MAX);
70        dis[k]=0;
71        for(int i=0;i<n-1;i++){
72            for(auto it: times){
73                int u=it[0];
74                int v=it[1];
75                int wt=it[2];
76                if(dis[u]!=INT_MAX && dis[u]+wt<dis[v]){
77                    dis[v]=dis[u]+wt;
78                }
79            }
80        }
81        int mx=*max_element(dis.begin()+1,dis.end());
82        if(mx==INT_MAX) return -1;
83        return mx;
84    }
85};