// Last updated: 9/24/2026, 9:24:14 AM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<n;i++){
6            int x=nums[i]%10;
7            nums[i]=nums[i]/10;
8            int y=nums[i]%10;
9            nums[i]=nums[i]/10;
10            int z=nums[i]%10;
11            nums[i]=nums[i]/10;
12            int a=nums[i]%10;
13            if(x+y+z+a==i){
14                return i;
15            }
16        }
17        return -1;
18    }
19};