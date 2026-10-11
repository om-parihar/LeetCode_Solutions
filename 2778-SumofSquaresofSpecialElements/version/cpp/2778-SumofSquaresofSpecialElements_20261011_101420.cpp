// Last updated: 10/11/2026, 10:14:20 AM
1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int ans=0;
5        for(int i=0;i<nums.size();i++){
6            if(nums.size()%(i+1)==0){
7                ans+=nums[i]*nums[i];
8            }
9        }
10        return ans;
11    }
12};