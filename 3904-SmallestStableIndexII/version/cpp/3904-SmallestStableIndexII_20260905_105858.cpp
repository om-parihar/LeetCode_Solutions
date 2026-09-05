// Last updated: 9/5/2026, 10:58:58 AM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4         int n=nums.size();
5         vector<int> maxi;
6         int mx=INT_MIN;
7         for(int i=0;i<n;i++){
8            if(nums[i]>mx){
9                mx=nums[i];
10            }
11            maxi.push_back(mx);
12         }
13         vector<int> mini;
14         int mn=INT_MAX;
15         for(int i=n-1;i>=0;i--){
16            if(nums[i]<mn){
17                mn=nums[i];
18            }
19            mini.push_back(mn);
20         }
21         for(int i=0;i<n;i++){
22            if(maxi[i]-mini[n-1-i]<=k){
23                return i;
24            }
25         }
26         return -1;
27    }
28};