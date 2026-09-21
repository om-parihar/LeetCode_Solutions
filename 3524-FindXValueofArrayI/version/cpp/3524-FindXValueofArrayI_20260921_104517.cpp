// Last updated: 9/21/2026, 10:45:17 AM
1class Solution {
2public:
3    void solve(int i, vector<int>& nums, int k, vector<long long>& ans,vector<long long>& dp){
4        if(i==nums.size()){
5            return;
6        }
7        vector<long long> newdp(k,0);
8        int rem=nums[i]%k;
9        newdp[rem]++;
10        for(int a=0;a<k;a++){
11            if(dp[a]==0) continue;
12            long long newrem=(1LL*a*nums[i])%k;
13            newdp[newrem]+=dp[a];
14        }
15        dp=newdp;
16        for(int a=0;a<k;a++){
17            ans[a]+=newdp[a];
18        }
19        solve(i+1,nums,k,ans,dp);
20    }
21    vector<long long> resultArray(vector<int>& nums, int k) {
22        vector<long long> ans(k,0);
23        vector<long long> dp(k,0);
24        solve(0,nums,k,ans,dp);
25        return ans;
26    }
27};
28
29
30class Solution1 {
31public:
32    vector<long long> resultArray(vector<int>& nums, int k) {
33        vector<long long> ans(k,0);
34        for(int i=0;i<nums.size();i++){
35            long long prod=1;
36            for(int j=i;j<nums.size();j++){
37                prod=(prod*nums[j])%k;
38                ans[prod]++;
39            }
40        }
41        return ans;
42    }
43};