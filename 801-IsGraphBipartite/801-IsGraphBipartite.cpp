// Last updated: 7/30/2026, 7:03:24 PM
class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>> &graph, vector<int> &coloured){
        coloured[node]=col;
        for(int it:graph[node]){
            if(coloured[it]==-1){
                if(dfs(it,!col,graph,coloured)==false) return false;
            }
            else if(coloured[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> coloured(v,-1);
        for(int i=0;i<graph.size();i++){
            if(coloured[i]==-1){
                if(dfs(i,0,graph,coloured)==false) return false;
            }
        }
        return true;
    }
};