// Last updated: 10/26/2026, 11:55:45 PM
1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        string ans="";
5        int n=s.size();
6        vector<int> freq(26,0);
7        for(int i=0;i<n;i++){
8            freq[s[i]-'a']++;
9        }
10        vector<int> visited(26, 0);
11
12        for(char c : s) {
13            freq[c - 'a']--;
14
15            if(visited[c - 'a']) continue;
16
17            while(!ans.empty() && ans.back() > c && freq[ans.back() - 'a'] > 0) {
18                visited[ans.back() - 'a'] = 0;
19                ans.pop_back();
20            }
21
22            ans += c;
23            visited[c - 'a'] = 1;
24        }
25
26        return ans;
27    }
28};