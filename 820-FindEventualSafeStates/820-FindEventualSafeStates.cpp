// Last updated: 7/30/2026, 7:03:22 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> edges(n);
        vector<int> topo;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                edges[it].push_back(i);
                outdegree[i]++;
                //outdegree[i] = graph[i].size();
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int a=q.front();
            q.pop();
            topo.push_back(a);
            for(auto it:edges[a]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};