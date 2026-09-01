// Last updated: 9/1/2026, 10:41:06 AM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n=nums.size();
5        stack<int> st;
6        vector<int> ans(n,-1);
7        for(int i=2*n-1;i>=0;i--){
8            int idx=i%n;
9            while(!st.empty() && st.top()<=nums[idx]){
10                st.pop();
11            }
12            if(!st.empty()){
13                ans[idx]=st.top();
14            }
15            st.push(nums[idx]);
16        }
17        return ans;
18    }
19};