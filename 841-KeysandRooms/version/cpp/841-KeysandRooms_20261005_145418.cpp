// Last updated: 10/5/2026, 2:54:18 PM
1class Solution {
2public:
3    void dfs(int i, vector<vector<int>>& rooms, vector<int>& vis){
4        vis[i]=1;
5        for(auto it: rooms[i]){
6            if(!vis[it]){
7                dfs(it,rooms,vis);
8            }
9        }
10    }
11    bool canVisitAllRooms(vector<vector<int>>& rooms) {
12        int n=rooms.size();
13        vector<int> vis(n,0);
14        dfs(0,rooms,vis);
15        for(int i=0;i<vis.size();i++){
16            if(vis[i]==0){
17                return false;
18            }
19        }
20        return true;
21    }
22};