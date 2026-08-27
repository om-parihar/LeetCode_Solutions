// Last updated: 8/27/2026, 2:32:10 PM
1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        int n = s.size();
5        vector<int> cnt(26);
6
7        for (char c : s)
8            cnt[c - 'a']++;
9
10        vector<int> temp = cnt;
11        int pos = -1;
12
13        for (int i = 0; i < n; i++) {
14            int x = target[i] - 'a';
15
16            for (int j = x + 1; j < 26; j++) {
17                if (temp[j] > 0) {
18                    pos = i;
19                    break;
20                }
21            }
22
23            if (temp[x] == 0)
24                break;
25
26            temp[x]--;
27        }
28
29        if (pos == -1)
30            return "";
31
32        string ans;
33
34        for (int i = 0; i < pos; i++) {
35            ans += target[i];
36            cnt[target[i] - 'a']--;
37        }
38
39        int x = target[pos] - 'a';
40
41        for (int j = x + 1; j < 26; j++) {
42            if (cnt[j] > 0) {
43                ans += char('a' + j);
44                cnt[j]--;
45                break;
46            }
47        }
48
49        for (int i = 0; i < 26; i++) {
50            while (cnt[i] > 0) {
51                ans += char('a' + i);
52                cnt[i]--;
53            }
54        }
55
56        return ans;
57    }
58};