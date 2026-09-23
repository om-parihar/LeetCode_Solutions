// Last updated: 9/23/2026, 10:14:48 AM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n=nums.size();
5        int total_sum=0;
6        for(int it:nums){
7            total_sum+=it;
8        }
9        int target=total_sum-x;
10        if(target<0) return -1;
11        if(target==0) return n;
12        int left=0;
13        int win_sum=0;
14        int ans=0;
15        for(int right=0;right<n;right++){
16            win_sum+=nums[right];
17            while(left<n && win_sum>target){
18                win_sum-=nums[left];
19                left++;
20            }
21            if(win_sum==target){
22                ans=max(ans,right-left+1);
23            }
24        }
25        if(ans==0) return -1;
26        return n-ans;
27    }
28};