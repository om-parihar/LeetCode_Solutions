// Last updated: 7/25/2026, 11:02:18 PM
class Solution {
public:
    void find(int idx,vector<int> &nums,int n, vector<vector<int>> &ans, vector<int> &ds){
        if(idx>n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        find(idx+1,nums,n,ans,ds);
        ds.pop_back();
        find(idx+1,nums,n,ans,ds);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,nums,nums.size()-1,ans,ds);
        return ans;
    }
};