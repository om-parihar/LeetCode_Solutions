// Last updated: 8/9/2026, 4:26:37 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> res;
5        int n=nums.size();
6        if(n<3) return res;
7        sort(nums.begin(),nums.end());
8        for(int i=0;i<n-2;i++){
9            if(i>0 && nums[i]==nums[i-1]) continue;
10            int left=i+1;
11            int right=n-1;
12            while(left<right){
13                int sum=nums[i]+nums[left]+nums[right];
14                if(sum==0){
15                    res.push_back({nums[i], nums[left], nums[right]});
16                    while (left<right && nums[left]==nums[left+1]) left++;
17                    while (left<right && nums[right]==nums[right-1]) right--;
18                    left++;
19                    right--;
20                } else if(sum<0) {
21                    left++;
22                } else {
23                    right--;
24                }
25            }
26        }
27        
28        return res;
29    }
30};