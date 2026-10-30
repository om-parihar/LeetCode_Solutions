// Last updated: 10/30/2026, 6:28:15 PM
1class Solution {
2public:
3    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
4        vector<vector<pair<int,int>>> adj(n+1);
5        for(int i=0;i<edges.size();i++){
6            int u=edges[i][0];
7            int v=edges[i][1];
8            int w=edges[i][2];
9            adj[u].push_back({v,w});
10        }
11        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
12        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
13        dist[0][1] = 0;
14        pq.push({0,{0,1}});
15        while(!pq.empty()){
16            int dis=pq.top().first;
17            int node=pq.top().second.first;
18            int count=pq.top().second.second;
19            pq.pop();
20            if(node==n-1) return dis;
21            if(dis > dist[node][count]) continue;
22            for(auto it : adj[node]) {
23            int nextNode = it.first;
24            int weight = it.second;
25
26            int nextCount;
27
28            if(labels[node] == labels[nextNode])
29                nextCount = count + 1;
30            else
31                nextCount = 1;
32
33            if(nextCount > k) continue;
34            int newDistance = dis + weight;
35
36            if(newDistance < dist[nextNode][nextCount]) {
37                dist[nextNode][nextCount] = newDistance;
38                pq.push({newDistance, {nextNode, nextCount}});
39                }
40            }
41        }
42        return -1;
43    }
44};