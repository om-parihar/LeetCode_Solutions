// Last updated: 9/6/2026, 1:06:41 AM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n=nums.size();
5        int farthest=0;
6        int end=0;
7        int jumps=0;
8        for(int i=0;i<n-1;i++){
9            farthest = max(farthest,i+nums[i]);
10            if(i==end){
11                jumps++;
12                end=farthest;
13            }
14        }
15        return jumps;
16    }
17};