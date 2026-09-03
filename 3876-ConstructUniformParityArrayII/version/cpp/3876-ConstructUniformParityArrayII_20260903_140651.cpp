// Last updated: 9/3/2026, 2:06:51 PM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums) {
4        int minOdd=INT_MAX;
5        int minEven=INT_MAX;
6
7        for(int x:nums){
8            if(x%2)
9                minOdd=min(minOdd,x);
10            else
11                minEven=min(minEven,x);
12        }
13
14        if(minOdd==INT_MAX)
15            return true;
16
17        if(minEven==INT_MAX)
18            return true;
19
20        return minOdd<minEven;
21    }
22};