// Last updated: 7/29/2026, 11:29:05 PM
1class Solution1 {
2public:
3    bool check(int node, vector<vector<int>> &edges, vector<int> &vis, vector<int> &path){
4        vis[node]=1;
5        path[node]=1;
6        for(auto it: edges[node]){
7            if(!vis[it]){
8                if(check(it,edges,vis,path)) return true;
9            }
10            else if(path[it]==1) return true;
11        }
12        path[node]=0;
13        return false;
14    }
15    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
16        vector<int> vis(numCourses,0);
17        vector<vector<int>> edges(numCourses);
18        for(int i=0;i<prerequisites.size();i++){
19            int u=prerequisites[i][0];
20            int v=prerequisites[i][1];
21            edges[u].push_back(v);
22        }
23        vector<int> path(numCourses,0);
24        for(int i=0;i<numCourses;i++){
25            if(!vis[i]){
26                if(check(i,edges,vis,path)) return false;
27            }
28        }
29        return true;
30    }
31};
32
33
34class Solution {
35public:
36    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
37        vector<int> indegree(numCourses,0);
38        vector<vector<int>> edges(numCourses);
39        for(int i=0;i<prerequisites.size();i++){
40            int u=prerequisites[i][0];
41            int v=prerequisites[i][1];
42            edges[v].push_back(u);
43        }
44        queue<int> q;
45        vector<int> topo;
46        for(int i=0;i<numCourses;i++){
47            for(auto it:edges[i]){
48                indegree[it]++;
49            }
50        }
51        for(int i=0;i<numCourses;i++){
52            if(indegree[i]==0){
53                q.push(i);
54            }
55        }
56        while(!q.empty()){
57            int a=q.front();
58            q.pop();
59            topo.push_back(a);
60            for(auto it:edges[a]){
61                indegree[it]--;
62                if(indegree[it]==0){
63                    q.push(it);
64                }
65            }
66        }
67        if(topo.size()==numCourses) return true;
68        return false;
69    }
70};