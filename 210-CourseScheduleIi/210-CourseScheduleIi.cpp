// Last updated: 8/31/2026, 4:32:40 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> edges(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            edges[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            for(auto it:edges[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            topo.push_back(a);
            for(auto it: edges[a]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()!=numCourses){
            return {};
        }
        return topo;
    }
};