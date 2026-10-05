// Last updated: 10/5/2026, 5:59:48 PM
1class Solution {
2public:
3    bool count(int i, int j, string& s, string& t){
4        if(i==s.size()) return true;
5        if(j==t.size()) return false;
6        if(s[i]==t[j]){
7            return count(i+1,j+1,s,t);
8        }else{
9            return count(i,j+1,s,t);
10        }
11    }
12    bool isSubsequence(string s, string t) {
13        return count(0,0,s,t);
14    }
15};