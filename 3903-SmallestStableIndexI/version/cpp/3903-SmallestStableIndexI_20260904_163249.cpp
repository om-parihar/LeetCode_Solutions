// Last updated: 9/4/2026, 4:32:49 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int stability=-1;
5        int n=nums.size();
6        for(int i=0;i<n;i++){
7            int mn=INT_MAX;
8            int mx=INT_MIN;
9            for(int j=0;j<=i;j++){
10                mx=max(mx,nums[j]);
11            }
12            for(int k=i;k<n;k++){
13                mn=min(mn,nums[k]);
14            }
15            if(mx-mn<=k){
16                stability=i;
17                break;
18            }
19        }
20        return stability;
21    }
22};