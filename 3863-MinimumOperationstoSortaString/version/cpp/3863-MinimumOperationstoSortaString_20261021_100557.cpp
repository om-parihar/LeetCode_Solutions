// Last updated: 10/21/2026, 10:05:57 AM
1class Solution {
2public:
3    int minOperations(string s) {
4        int n = s.size();
5
6        if (is_sorted(s.begin(), s.end()))
7            return 0;
8
9        if (n == 2)
10            return -1;
11
12        char mn = *min_element(s.begin(), s.end());
13        char mx = *max_element(s.begin(), s.end());
14
15        if (s[0] == mn || s[n - 1] == mx)
16            return 1;
17
18        for (int i = 1; i < n - 1; i++) {
19            if (s[i] == mn || s[i] == mx)
20                return 2;
21        }
22
23        return 3;
24    }
25};