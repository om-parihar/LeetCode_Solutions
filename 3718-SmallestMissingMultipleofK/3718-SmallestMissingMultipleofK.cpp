// Last updated: 8/25/2026, 9:23:56 PM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int ans=k;
5        unordered_set<int> st(nums.begin(),nums.end());
6        while(st.count(ans)){
7            ans+=k;
8        }
9        return ans;
10    }
11};
12
13class Solution1 {
14public:
15    int missingMultiple(vector<int>& nums, int k) {
16        int ans=k;
17        while(1){
18            int flg=0;
19            for(auto it: nums){
20                if(it==ans){
21                    flg=1;
22                    break;
23                }
24            }
25            if(flg==0){
26                break;
27            }
28            ans+=k;
29        }
30        return ans;
31    }
32};