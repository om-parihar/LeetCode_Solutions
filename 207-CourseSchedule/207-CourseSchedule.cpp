// Last updated: 7/29/2026, 11:22:21 PM
1class Solution {
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