// Last updated: 9/3/2026, 2:46:54 PM
1class Solution {
2public:
3    int count(int i, vector<int>& nums, int target,vector<int>& dp){
4        if(target==0){
5            return 1;
6        }
7        if(i<0 || target<0){
8            return 0;
9        }
10        if(dp[target]!=-1) return dp[target];
11        int ans=0;
12        for(int start=i;start<nums.size();start++){
13            if(nums[start]<=target){
14                ans += count(0,nums,target-nums[start],dp);
15            }
16        }
17        return dp[target]=ans;
18    }
19    int combinationSum4(vector<int>& nums, int target) {
20        int n=nums.size();
21        vector<int> dp(target+1,-1);
22        return count(0,nums,target,dp);
23    }
24};
25
26class Solution1 {
27public:
28    void count(int i, vector<int>& nums, int target, int &cnt){
29        if(target==0){
30            cnt++;
31            return;
32        }
33        if(i<0 || target<0){
34            return;
35        }
36        for(int start=i;start<nums.size();start++){
37            if(nums[start]<=target){
38                count(0,nums,target-nums[start],cnt);
39            }
40        }
41    }
42    int combinationSum4(vector<int>& nums, int target) {
43        int n=nums.size();
44        int cnt=0;
45        count(0,nums,target,cnt);
46        return cnt;
47    }
48};