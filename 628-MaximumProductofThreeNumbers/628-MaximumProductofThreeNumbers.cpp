// Last updated: 7/26/2026, 3:58:13 PM
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
5        int min1 = INT_MAX, min2 = INT_MAX;
6
7        for(int x : nums) {
8
9            if(x >= max1) {
10                max3 = max2;
11                max2 = max1;
12                max1 = x;
13            }
14            else if(x >= max2) {
15                max3 = max2;
16                max2 = x;
17            }
18            else if(x >= max3) {
19                max3 = x;
20            }
21
22            if(x <= min1) {
23                min2 = min1;
24                min1 = x;
25            }
26            else if(x <= min2) {
27                min2 = x;
28            }
29        }
30
31        return max(max1 * max2 * max3, min1 * min2 * max1);
32    }
33};