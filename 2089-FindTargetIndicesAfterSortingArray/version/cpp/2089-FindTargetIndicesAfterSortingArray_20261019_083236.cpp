// Last updated: 10/19/2026, 8:32:36 AM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int n=nums.size();
5        vector<int> ans;
6        sort(nums.begin(),nums.end());
7        for(int i=0;i<n;i++){
8            if(nums[i]==target){
9                ans.push_back(i);
10            }
11        }
12        return ans;
13    }
14};