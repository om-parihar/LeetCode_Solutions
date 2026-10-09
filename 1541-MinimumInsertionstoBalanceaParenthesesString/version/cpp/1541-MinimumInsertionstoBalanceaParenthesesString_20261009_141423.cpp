// Last updated: 10/9/2026, 2:14:23 PM
1class Solution {
2public:
3    int minInsertions(std::string s) {
4        int insertions = 0;
5        int open_count = 0;
6        
7        for (int i = 0; i < s.length(); i++) {
8            if (s[i] == '(') {
9                open_count++;
10            } else {
11                if (i + 1 < s.length() && s[i + 1] == ')') {
12                    i++;
13                } else {
14                    insertions++;
15                }
16                
17                if (open_count > 0) {
18                    open_count--;
19                } else {
20                    insertions++;
21                }
22            }
23        }
24        
25        insertions += open_count * 2;
26        return insertions;
27    }
28};