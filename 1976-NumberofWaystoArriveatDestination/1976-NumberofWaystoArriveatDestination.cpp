// Last updated: 8/6/2026, 2:48:13 PM
1class Solution {
2public:
3    int countPaths(int n, vector<vector<int>>& roads) {
4        vector<vector<pair<int,int>>> edge(n);
5        for(auto it: roads){
6            edge[it[0]].push_back({it[1],it[2]});
7            edge[it[1]].push_back({it[0],it[2]});
8        }
9        priority_queue<pair<long long,int>,
10                    vector<pair<long long,int>>,
11                    greater<pair<long long,int>>> pq;
12        vector<int> ways(n,0);
13        vector<long long> vis(n,LLONG_MAX);
14        pq.push({0,0});
15        vis[0]=0;
16        ways[0]=1;
17        int MOD=(int)(1e9+7);
18        while(!pq.empty()){
19            long long dis=pq.top().first;
20            int node=pq.top().second;
21            pq.pop();
22            if(dis > vis[node]) continue;
23            for(auto it: edge[node]){
24                int n=it.first;
25                int cost=it.second;
26                if(cost+dis<vis[n]){
27                    vis[n]=cost+dis;
28                    pq.push({cost+dis,n});
29                    ways[n]=ways[node];
30                }
31                else if(cost+dis==vis[n]){
32                    ways[n]=(ways[node]+ways[n])%MOD;
33                }
34            }
35        }
36        return ways[n-1]%MOD;
37    }
38};