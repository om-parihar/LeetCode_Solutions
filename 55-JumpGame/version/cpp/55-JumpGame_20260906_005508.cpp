// Last updated: 9/6/2026, 12:55:08 AM
1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n=nums.size();
5        int mx=0;
6        for(int i=0;i<n;i++){
7            if(i>mx){
8                return false;
9            }
10            mx=max(mx,i+nums[i]);
11            if(mx>=n-1){
12                return true;
13            }
14        }
15        return false;
16    }
17};