// Last updated: 7/25/2026, 11:02:50 PM
class Solution {
public:
    void find(int idx, int target, vector<int> &candidate, vector<vector<int>> &ans, vector<int> &ds ){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<candidate.size();i++){
            if(i>idx && candidate[i]==candidate[i-1]) continue;
            if(candidate[i]>target) break;
            ds.push_back(candidate[i]);
            find(i+1,target-candidate[i],candidate,ans,ds);
            ds.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,target,candidates,ans,ds);
        return ans;
    }
};