// Last updated: 10/15/2026, 1:53:15 PM
1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0;
6        for(int i=0;i<n;i++){
7            for(int j=i;j<n;j++){
8                set<int> st;
9                for(int k=i;k<=j;k++){
10                    st.insert(nums[k]);
11                }
12                ans+=(st.size()*st.size());
13            }
14        }
15        return ans;
16    }
17};