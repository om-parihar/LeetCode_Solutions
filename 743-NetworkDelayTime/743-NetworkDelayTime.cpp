// Last updated: 8/6/2026, 12:53:29 PM
1class Solution {
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