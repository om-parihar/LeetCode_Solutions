// Last updated: 8/26/2026, 5:25:47 PM
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        int n = s.size();
5        int i = 0;
6        int cnt = 0;
7
8        string ans = "";
9
10        for (int j = 0; j < n; j++) {
11
12            if (s[j] == '1')
13                cnt++;
14
15            while (cnt == k) {
16
17                string curr = s.substr(i, j - i + 1);
18
19                if (ans.empty() ||
20                    curr.size() < ans.size() ||
21                    (curr.size() == ans.size() && curr < ans)) {
22                    ans = curr;
23                }
24
25                if (s[i] == '1')
26                    cnt--;
27
28                i++;
29            }
30        }
31
32        return ans;
33    }
34};