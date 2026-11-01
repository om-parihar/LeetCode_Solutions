// Last updated: 11/1/2026, 4:00:46 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int ans=0;
5        int mn=*min_element(nums.begin(),nums.end());
6        for(int x:nums){
7            ans+=x-mn;
8        }
9        return ans;
10    }
11};