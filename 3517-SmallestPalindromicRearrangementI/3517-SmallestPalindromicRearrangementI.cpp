// Last updated: 7/28/2026, 4:47:23 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        vector<char> half;
5        for(int i=0;i<s.size()/2;i++){
6            half.push_back(s[i]);
7        }
8        sort(half.begin(),half.end());
9        string ans="";
10        for(int i=0;i<half.size();i++){
11            ans+=half[i];
12        }
13        if(s.size() % 2)
14            ans += s[s.size()/2];
15
16        for(int i=half.size()-1;i>=0;i--){
17            ans+=half[i];
18        }
19        return ans;
20    }
21};