// Last updated: 10/29/2026, 2:18:17 PM
1class Solution {
2public:
3    bool wordPattern(string pattern, string s) {
4        int n = s.size();
5        unordered_map<char, string> mp;
6        unordered_map<string, char> rev;
7        vector<string> str;
8
9        stringstream ss(s);
10        string temp;
11
12        while (ss >> temp) {
13            str.push_back(temp);
14        }
15
16        if (pattern.size() != str.size()) return false;
17
18        int i = 0;
19        for (char c : pattern) {
20            if (mp.find(c) != mp.end()) {
21                if (mp[c] != str[i]) return false;
22            } else {
23                mp[c] = str[i];
24            }
25
26            if (rev.find(str[i]) != rev.end()) {
27                if (rev[str[i]] != c) return false;
28            } else {
29                rev[str[i]] = c;
30            }
31
32            i++;
33        }
34
35        return true;
36    }
37};