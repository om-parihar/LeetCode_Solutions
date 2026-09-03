// Last updated: 9/3/2026, 2:50:04 PM
1class Solution {
2public:
3    int count(vector<int>& nums, int target,vector<int>& dp){
4        if(target==0){
5            return 1;
6        }
7        if(target<0){
8            return 0;
9        }
10        if(dp[target]!=-1) return dp[target];
11        int ans=0;
12        for(int start=0;start<nums.size();start++){
13            if(nums[start]<=target){
14                ans += count(nums,target-nums[start],dp);
15            }
16        }
17        return dp[target]=ans;
18    }
19    int combinationSum4(vector<int>& nums, int target) {
20        vector<int> dp(target+1,-1);
21        return count(nums,target,dp);
22    }
23};
24
25class Solution1 {
26public:
27    void count(int i, vector<int>& nums, int target, int &cnt){
28        if(target==0){
29            cnt++;
30            return;
31        }
32        if(i<0 || target<0){
33            return;
34        }
35        for(int start=i;start<nums.size();start++){
36            if(nums[start]<=target){
37                count(0,nums,target-nums[start],cnt);
38            }
39        }
40    }
41    int combinationSum4(vector<int>& nums, int target) {
42        int n=nums.size();
43        int cnt=0;
44        count(0,nums,target,cnt);
45        return cnt;
46    }
47};