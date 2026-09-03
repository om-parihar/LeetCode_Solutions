// Last updated: 9/3/2026, 2:58:07 PM
1class Solution {
2public:
3    int combinationSum4(vector<int>& nums, int target) {
4        vector<unsigned int> dp(target+1,0);
5        dp[0]=1;
6
7        for(int t=1;t<=target;t++){
8            for(int i=0;i<nums.size();i++){
9                if(nums[i]<=t)
10                    dp[t]+=dp[t-nums[i]];
11            }
12        }
13
14        return dp[target];
15    }
16};
17
18class Solution2 {
19public:
20    int count(vector<int>& nums, int target,vector<int>& dp){
21        if(target==0){
22            return 1;
23        }
24        if(target<0){
25            return 0;
26        }
27        if(dp[target]!=-1) return dp[target];
28        int ans=0;
29        for(int start=0;start<nums.size();start++){
30            if(nums[start]<=target){
31                ans += count(nums,target-nums[start],dp);
32            }
33        }
34        return dp[target]=ans;
35    }
36    int combinationSum4(vector<int>& nums, int target) {
37        vector<int> dp(target+1,-1);
38        return count(nums,target,dp);
39    }
40};
41
42class Solution1 {
43public:
44    void count(int i, vector<int>& nums, int target, int &cnt){
45        if(target==0){
46            cnt++;
47            return;
48        }
49        if(i<0 || target<0){
50            return;
51        }
52        for(int start=i;start<nums.size();start++){
53            if(nums[start]<=target){
54                count(0,nums,target-nums[start],cnt);
55            }
56        }
57    }
58    int combinationSum4(vector<int>& nums, int target) {
59        int n=nums.size();
60        int cnt=0;
61        count(0,nums,target,cnt);
62        return cnt;
63    }
64};