// Last updated: 10/17/2026, 7:06:21 PM
1class Solution {
2public:
3    int findLengthOfLCIS(vector<int>& nums) {
4        if(nums.empty()) return 0;
5        int n=nums.size();
6        int currlen=1;
7        int maxlen=1;
8        for(int i=1;i<n;i++){
9            if(nums[i]>nums[i-1]){
10                currlen++;
11            }
12            else{
13                currlen=1;
14            }
15            maxlen=max(maxlen,currlen);
16        }
17        return maxlen;
18    }
19};