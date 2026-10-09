// Last updated: 10/9/2026, 2:14:12 PM
1#include <string>
2
3class Solution {
4public:
5    int minInsertions(std::string s) {
6        int insertions = 0;
7        int open_count = 0;
8        
9        for (int i = 0; i < s.length(); i++) {
10            if (s[i] == '(') {
11                open_count++;
12            } else {
13                if (i + 1 < s.length() && s[i + 1] == ')') {
14                    i++;
15                } else {
16                    insertions++;
17                }
18                
19                if (open_count > 0) {
20                    open_count--;
21                } else {
22                    insertions++;
23                }
24            }
25        }
26        
27        insertions += open_count * 2;
28        return insertions;
29    }
30};