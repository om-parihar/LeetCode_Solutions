// Last updated: 11/3/2026, 10:08:30 PM
1class Solution {
2public:
3    int minimizeArrayValue(vector<int>& nums) {
4        int n=nums.size();
5        int mx=INT_MIN;
6        long long sum=0;
7        for(int i=0;i<n;i++){
8            sum+=nums[i];
9            mx=max(mx,(int)((i+sum)/(i+1)));
10        }
11        return mx;
12    }
13};