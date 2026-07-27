// Last updated: 7/27/2026, 3:46:09 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int fmax=0;
5        int smax=0;
6        for(int it:nums){
7            if(it>=fmax){
8                smax=fmax;
9                fmax=it;
10            }
11            else if(it>=smax){
12                smax=it;
13            }
14        }
15        return ((fmax-1)*(smax-1));
16    }
17};