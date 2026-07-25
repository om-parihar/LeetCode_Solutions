// Last updated: 7/25/2026, 11:02:07 PM
class Solution {
public:
    void fun(int idx, vector<int> &nums, int n, set<vector<int>> &st, vector<int> &ds){
        if(idx>n){
            st.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        fun(idx+1,nums,n,st,ds);
        ds.pop_back();
        fun(idx+1,nums,n,st,ds);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ds;
        set<vector<int>> st;
        fun(0,nums,n-1,st,ds);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};