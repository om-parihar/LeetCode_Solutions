// Last updated: 10/7/2026, 4:42:03 PM
1#include <vector>
2#include <string>
3#include <queue>
4#include <unordered_set>
5
6using namespace std;
7
8class Solution {
9    bool isValid(const string& str) {
10        int count = 0;
11        for (char c : str) {
12            if (c == '(') count++;
13            else if (c == ')') {
14                count--;
15                if (count < 0) return false;
16            }
17        }
18        return count == 0;
19    }
20
21public:
22    vector<string> removeInvalidParentheses(string s) {
23        vector<string> result;
24        unordered_set<string> visited;
25        queue<string> q;
26
27        q.push(s);
28        visited.insert(s);
29
30        bool found = false;
31
32        while (!q.empty()) {
33            string curr = q.front();
34            q.pop();
35
36            if (isValid(curr)) {
37                result.push_back(curr);
38                found = true;
39            }
40
41            if (found) continue;
42
43            for (int i = 0; i < curr.length(); i++) {
44                if (curr[i] != '(' && curr[i] != ')') continue;
45
46                string nextState = curr.substr(0, i) + curr.substr(i + 1);
47                if (visited.find(nextState) == visited.end()) {
48                    visited.insert(nextState);
49                    q.push(nextState);
50                }
51            }
52        }
53
54        return result;
55    }
56};
57
58class Solution1 {
59public:
60    bool isvalid(string& temp){
61        int lc=0;
62        for(char c: temp){
63            if(c=='('){
64                lc++;
65            }
66            else{
67                lc--;
68                if(lc<0) return 0;
69            }
70        }
71        return lc==0;
72    }
73    void count(int i, string& s, string& temp, unordered_set<string>& ans, int & maxLen){
74        if (i == s.size()) {
75            if (isvalid(temp)) {
76                if (temp.length() > maxLen) {
77                    maxLen = temp.length();
78                    ans.clear();
79                    ans.insert(temp);
80                } else if (temp.length() == maxLen) {
81                    ans.insert(temp);
82                }
83            }
84            return;
85        }
86        if(s[i]!='(' && s[i]!=')'){
87            temp+=s[i];
88            count(i+1,s,temp,ans,maxLen);
89            temp.pop_back();
90            return;
91        }
92        temp+=s[i];
93        count(i+1,s,temp,ans,maxLen);
94        temp.pop_back();
95        count(i+1,s,temp,ans,maxLen);
96    }
97    vector<string> removeInvalidParentheses(string s) {
98        unordered_set<string> ans;
99        string temp="";
100        int maxLen=0;
101        count(0,s,temp,ans,maxLen);
102        return vector<string>(ans.begin(),ans.end());
103    }
104};