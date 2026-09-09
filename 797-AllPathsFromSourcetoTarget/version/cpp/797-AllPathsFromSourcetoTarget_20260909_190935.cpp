// Last updated: 9/9/2026, 7:09:35 PM
1class Solution {
2public:
3    void count(vector<vector<int>>& graph, int s, vector<int>&temp, vector<vector<int>>& all) {
4        temp.push_back(s);
5
6        if(s==graph.size()-1){
7            all.push_back(temp);
8            temp.pop_back();
9            return;
10        }
11
12        for(auto x:graph[s]){
13            count(graph,x,temp,all);
14        }
15
16        temp.pop_back();
17    }
18
19    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
20        vector<vector<int>> all;
21        vector<int> temp;
22        count(graph,0,temp,all);
23        return all;
24    }
25};
26
27class Solution1 {
28public:
29    void count(vector<vector<int>>& graph, int s, vector<int>&temp, vector<vector<int>>& all) {
30        if(s==graph.size()-1){
31            temp.push_back(s);
32            all.push_back(temp);
33            temp.pop_back();
34            return;
35        }
36        for(auto x:graph[s]){
37            temp.push_back(s);
38            count(graph,x,temp,all);
39            temp.pop_back();
40        }
41    }
42    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
43        vector<vector<int>> all;
44        vector<int> temp;
45        count(graph,0,temp,all);
46        return all;
47    }
48};