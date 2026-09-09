// Last updated: 9/9/2026, 9:47:51 AM
1class Solution {
2public:
3    long long countCommas(long long n) {
4        long long ans = 0;
5
6        if (n >= 1000)
7            ans += n - 999;
8
9        if (n >= 1000000)
10            ans += n - 999999;
11
12        if (n >= 1000000000)
13            ans += n - 999999999;
14
15        if (n >= 1000000000000)
16            ans += n - 999999999999;
17
18        if (n >= 1000000000000000)
19            ans += n - 999999999999999;
20        return ans;
21    }
22};