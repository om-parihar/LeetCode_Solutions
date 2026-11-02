// Last updated: 11/2/2026, 9:35:13 AM
1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        int cnt=0;
5        sort(nums.begin(),nums.end());
6        int ele=nums[nums.size()/2];
7        for(int x:nums){
8            cnt+=abs(x-ele);
9        }
10        return cnt;   
11    }
12};