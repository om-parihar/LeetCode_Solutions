// Last updated: 8/16/2026, 6:58:13 PM
1class Solution {
2public:
3    int fun(int i, int newtarget, vector<int>& nums, vector<vector<int>> &dp){
4        if(i==0){
5            if(newtarget==0 && nums[i]==0) return 2;
6            if(newtarget==0 || newtarget==nums[0]) return 1;
7            return 0;
8        }
9        if(dp[i][newtarget]!=-1) return dp[i][newtarget];
10        int notake=fun(i-1,newtarget,nums,dp);
11        int take=0;
12        if(nums[i]<=newtarget){
13            take=fun(i-1,newtarget-nums[i],nums,dp);
14        }
15        return dp[i][newtarget] = take+notake;
16    }
17    int findTargetSumWays(vector<int>& nums, int target) {
18        int n=nums.size();
19        int total = accumulate(nums.begin(), nums.end(), 0);
20
21        if(total < abs(target))
22            return 0;
23
24        if((total + target) % 2 != 0)
25            return 0;
26        int newtarget = (total + target) / 2;
27        vector<vector<int>> dp(n,vector<int>(newtarget+1,-1));
28        return fun(n-1,newtarget,nums,dp);
29    }
30};
31
32class Solution1 {
33public:
34    int fun(int i, int newtarget, vector<int>& nums){
35        if(i==0){
36            if(newtarget==0 && nums[i]==0) return 2;
37            if(newtarget==0 || newtarget==nums[0]) return 1;
38            return 0;
39        }
40        int notake=fun(i-1,newtarget,nums);
41        int take=0;
42        if(nums[i]<=newtarget){
43            take=fun(i-1,newtarget-nums[i],nums);
44        }
45        return take+notake;
46    }
47    int findTargetSumWays(vector<int>& nums, int target) {
48        int n=nums.size();
49        int total = accumulate(nums.begin(), nums.end(), 0);
50
51        if(total < abs(target))
52            return 0;
53
54        if((total + target) % 2 != 0)
55            return 0;
56
57        int newtarget = (total + target) / 2;
58        return fun(n-1,newtarget,nums);
59    }
60};