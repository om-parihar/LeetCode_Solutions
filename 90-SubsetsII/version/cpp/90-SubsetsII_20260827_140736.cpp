// Last updated: 8/27/2026, 2:07:36 PM
1class Solution {
2public:
3    void fun(int idx, vector<int> &nums, int n, set<vector<int>> &st, vector<int> &ds){
4        if(idx>n){
5            st.insert(ds);
6            return;
7        }
8        ds.push_back(nums[idx]);
9        fun(idx+1,nums,n,st,ds);
10        ds.pop_back();
11        fun(idx+1,nums,n,st,ds);
12    }
13public:
14    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
15        int n=nums.size();
16        sort(nums.begin(),nums.end());
17        vector<int> ds;
18        set<vector<int>> st;
19        fun(0,nums,n-1,st,ds);
20        vector<vector<int>> ans(st.begin(),st.end());
21        return ans;
22    }
23};