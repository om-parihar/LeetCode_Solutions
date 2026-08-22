// Last updated: 8/22/2026, 9:37:03 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int n=nums.size();
5        sort(nums.begin(),nums.end());
6        for(int i=1;i<n;i++){
7            if(nums[i]==nums[i-1]){
8                return nums[i];
9            }
10        }
11        return -1;
12    }
13};