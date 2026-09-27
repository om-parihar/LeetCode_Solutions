// Last updated: 9/27/2026, 1:00:31 PM
1class Solution {
2public:
3    void reverse(string &s, int i, int j) {
4        while(i<j){
5            swap(s[i],s[j]);
6            i++;
7            j--;
8        }
9    }
10    string reverseParentheses(string s) {
11        int n=s.size();
12        int i=0,j=0;
13        while(i<n){
14            if(s[i]==')'){
15                s[i]='0';
16                j=i-1;
17                while(s[j]!='('){
18                    j--;
19                }
20                s[j]='0';
21                reverse(s,j+1,i-1);
22            }
23            i++;
24        }
25        string ans="";
26        for(int i=0;i<n;i++){
27            if(s[i]=='0') continue;
28            ans+=s[i];
29        }
30        return ans;
31    }
32};