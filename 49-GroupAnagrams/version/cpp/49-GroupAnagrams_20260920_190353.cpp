// Last updated: 9/20/2026, 7:03:53 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for(string s : strs) {
7            vector<int> freq(26, 0);
8
9            for(char c : s) {
10                freq[c - 'a']++;
11            }
12
13            string key = "";
14
15            for(int i = 0; i < 26; i++) {
16                key += to_string(freq[i]) + "#";
17            }
18
19            mp[key].push_back(s);
20        }
21
22        vector<vector<string>> ans;
23
24        for(auto it : mp) {
25            ans.push_back(it.second);
26        }
27
28        return ans;
29    }
30};