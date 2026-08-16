// Last updated: 8/16/2026, 6:54:10 PM
1class Solution {
2public:
3    int fun(int i, int newtarget, vector<int>& nums){
4        if(i==0){
5            if(newtarget==0 && nums[i]==0) return 2;
6            if(newtarget==0 || newtarget==nums[0]) return 1;
7            return 0;
8        }
9        int notake=fun(i-1,newtarget,nums);
10        int take=0;
11        if(nums[i]<=newtarget){
12            take=fun(i-1,newtarget-nums[i],nums);
13        }
14        return take+notake;
15    }
16    int findTargetSumWays(vector<int>& nums, int target) {
17        int n=nums.size();
18        int total = accumulate(nums.begin(), nums.end(), 0);
19
20        if(total < abs(target))
21            return 0;
22
23        if((total + target) % 2 != 0)
24            return 0;
25
26        int newtarget = (total + target) / 2;
27        return fun(n-1,newtarget,nums);
28    }
29};