// Last updated: 8/25/2026, 9:20:59 PM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int ans=k;
5        while(1){
6            int flg=0;
7            for(auto it: nums){
8                if(it==ans){
9                    flg=1;
10                    break;
11                }
12            }
13            if(flg==0){
14                break;
15            }
16            ans+=k;
17        }
18        return ans;
19    }
20};