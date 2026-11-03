// Last updated: 11/3/2026, 11:18:48 AM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int ele=nums[nums.size()-1];
6        int cnt=0;
7        for(int x:nums){
8            cnt+=abs(x-ele);
9        }
10        return cnt;
11    }
12};