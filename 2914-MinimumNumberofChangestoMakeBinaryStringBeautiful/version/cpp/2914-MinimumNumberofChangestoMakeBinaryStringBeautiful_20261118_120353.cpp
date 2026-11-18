// Last updated: 11/18/2026, 12:03:53 PM
1class Solution {
2public:
3    int minChanges(string s) {
4        int n=s.size();
5        int cnt=0;
6        for(int i=1;i<n;i+=2){
7            if(s[i-1]!=s[i]){
8                cnt++;
9                s[i]=s[i-1];
10            }
11        }
12        return cnt;
13    }
14};