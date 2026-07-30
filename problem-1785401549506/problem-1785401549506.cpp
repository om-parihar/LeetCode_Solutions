// Last updated: 7/30/2026, 2:22:29 PM
1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4        int n=graph.size();
5        vector<int> outdegree(n,0);
6        vector<vector<int>> edges(n);
7        vector<int> topo;
8        for(int i=0;i<n;i++){
9            for(auto it:graph[i]){
10                edges[it].push_back(i);
11                outdegree[i]++;
12                //outdegree[i] = graph[i].size();
13            }
14        }
15        queue<int> q;
16        for(int i=0;i<n;i++){
17            if(outdegree[i]==0){
18                q.push(i);
19            }
20        }
21        
22        while(!q.empty()){
23            int a=q.front();
24            q.pop();
25            topo.push_back(a);
26            for(auto it:edges[a]){
27                outdegree[it]--;
28                if(outdegree[it]==0){
29                    q.push(it);
30                }
31            }
32        }
33        sort(topo.begin(),topo.end());
34        return topo;
35    }
36};