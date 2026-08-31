// Last updated: 8/31/2026, 6:18:54 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int mx=*max_element(nums2.begin(),nums2.end());
5        vector<int> nge(mx+1,-1);
6        int m=nums2.size();
7        stack<int> st;
8        for(int j=m-1;j>=0;j--){
9            while(!st.empty() && st.top()<=nums2[j]){
10                st.pop();
11            }
12            if(!st.empty()){
13                nge[nums2[j]]=st.top();
14            }
15            st.push(nums2[j]);
16        }
17        vector<int> ans(nums1.size());
18        for(int i=0;i<nums1.size();i++){
19            ans[i]=nge[nums1[i]];
20        }
21        return ans;
22    }
23};