// Last updated: 10/5/2026, 10:14:20 AM
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4        int n=s.size();
5        int sc=0;
6        int lc=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='('){
9                lc++;
10            }
11            else{
12                lc--;
13                if(s[i-1]=='('){
14                    sc+=(1<<lc);
15                }
16            }
17        }
18        return sc;
19    }
20};