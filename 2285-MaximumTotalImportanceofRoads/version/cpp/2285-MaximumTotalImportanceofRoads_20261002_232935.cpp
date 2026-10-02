// Last updated: 10/2/2026, 11:29:35 PM
1class Solution {
2public:
3    long long maximumImportance(int n, vector<vector<int>>& roads) {
4        vector<int> adj(n,0);
5        for(auto it:roads){
6            for(int i:it){
7                adj[i]++;
8            }
9        }
10        sort(adj.begin(),adj.end());
11        long long total=0;
12        for(int i=0;i<n;i++){
13            total+=(long long)adj[i]*(i+1);
14        }
15        return total;
16    }
17};