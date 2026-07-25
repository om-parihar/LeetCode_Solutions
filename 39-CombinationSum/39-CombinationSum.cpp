// Last updated: 7/25/2026, 11:02:52 PM
class Solution {
public:
    void find(int idx, int trg, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(idx==arr.size()){
            if(trg==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[idx]<=trg){
            ds.push_back(arr[idx]);
            find(idx,trg-arr[idx],arr,ans,ds);
            ds.pop_back();
        }
        find(idx+1,trg,arr,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,target,candidates,ans,ds);
        return ans;
    }
};