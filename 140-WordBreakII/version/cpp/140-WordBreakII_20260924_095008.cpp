// Last updated: 9/24/2026, 9:50:08 AM
1class Solution {
2public:
3    void solve(int i, string& temp, string& s, unordered_set<string>& st, vector<string>& ans){
4        if(i==s.size()){
5            ans.push_back(temp);
6            return;
7        }
8        for(int j=i;j<s.size();j++){
9            string word=s.substr(i,j-i+1);
10            if(st.count(word)){
11                int len=temp.length();
12                if(!temp.empty()){
13                    temp+=" ";
14                }
15                temp+=word;
16                solve(j+1,temp,s,st,ans);
17                temp.erase(len);
18            }
19        }
20    }
21    vector<string> wordBreak(string s, vector<string>& wordDict) {
22        unordered_set<string> st(wordDict.begin(),wordDict.end());
23        vector<string> ans;
24        string path="";
25        solve(0,path,s,st,ans);
26        return ans;
27    }
28};