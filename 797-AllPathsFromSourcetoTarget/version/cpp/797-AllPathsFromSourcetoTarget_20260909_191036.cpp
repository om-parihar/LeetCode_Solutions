// Last updated: 9/9/2026, 7:10:36 PM
1class Solution {
2public:
3    void count(vector<vector<int>>& graph, int s, vector<int>&temp, vector<vector<int>>& all) {
4        if(s==graph.size()-1){
5            temp.push_back(s);
6            all.push_back(temp);
7            temp.pop_back();
8            return;
9        }
10        for(auto x:graph[s]){
11            temp.push_back(s);
12            count(graph,x,temp,all);
13            temp.pop_back();
14        }
15    }
16    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
17        vector<vector<int>> all;
18        vector<int> temp;
19        count(graph,0,temp,all);
20        return all;
21    }
22};