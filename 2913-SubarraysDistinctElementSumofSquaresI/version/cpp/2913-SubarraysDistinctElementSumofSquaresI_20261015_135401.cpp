// Last updated: 10/15/2026, 1:54:01 PM
1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0;
6        for(int i=0;i<n;i++){
7            set<int> st;
8            for(int j=i;j<n;j++){
9                st.insert(nums[j]);
10                ans+=(st.size()*st.size());
11            }
12            st.clear();
13        }
14        return ans;
15    }
16};