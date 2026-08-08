// Last updated: 8/8/2026, 6:25:30 PM
1class Solution1 {
2public:
3    int fun(int idx, vector<int> &n){
4        if(idx==0) return n[idx];
5        if(idx<0) return 0;
6        int take=n[idx]+fun(idx-2,n);
7        int notake=0+fun(idx-1,n);
8        return max(take,notake);
9    }
10    int rob(vector<int>& nums) {
11        int n = nums.size();
12        if(n==1) return nums[0];
13        vector<int> temp1,temp2;
14        for(int i=0;i<n;i++){
15            if(i!=n-1) temp1.push_back(nums[i]);
16            if(i!=0) temp2.push_back(nums[i]);
17        }
18        int cnt=max(fun(temp1.size()-1,temp1),fun(temp2.size()-1,temp2));
19        return cnt;
20    }
21};
22
23class Solution {
24public:
25    int fun(int idx, vector<int> &n,vector<int> &dp){
26        if(idx==0) return n[idx];
27        if(idx<0) return 0;
28        if(dp[idx]!=-1) return dp[idx];
29        int take=n[idx]+fun(idx-2,n,dp);
30        int notake=0+fun(idx-1,n,dp);
31        return dp[idx]=max(take,notake);
32    }
33    int rob(vector<int>& nums) {
34        int n = nums.size();
35        if(n==1) return nums[0];
36        vector<int> dp(n+1,-1);
37        vector<int> temp1,temp2;
38        for(int i=0;i<n;i++){
39            if(i!=n-1) temp1.push_back(nums[i]);
40            if(i!=0) temp2.push_back(nums[i]);
41        }
42        int cnt1=fun(temp1.size()-1,temp1,dp);
43        fill(dp.begin(),dp.end(),-1);
44        int cnt2=fun(temp2.size()-1,temp2,dp);
45        return max(cnt1,cnt2);
46    }
47};