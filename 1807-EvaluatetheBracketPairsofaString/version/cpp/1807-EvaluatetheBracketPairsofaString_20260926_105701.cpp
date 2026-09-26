// Last updated: 9/26/2026, 10:57:01 AM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string,string> mp;
5        for(int i=0;i<knowledge.size();i++){
6            mp[knowledge[i][0]]=knowledge[i][1];
7        }
8        int i=0,j=0;
9        string ans="";
10        while(i<s.size() && j<s.size()){
11            if(s[i]=='('){
12                j=i+1;
13                string val;
14                while(s[j]!=')'){
15                    val+=s[j];
16                    j++;
17                }
18                i=j+1;
19                if(mp.find(val)==mp.end()) ans+='?';
20                else ans+=mp[val];
21            }
22            else{
23                ans+=s[i];
24                i++;
25            }
26        }
27        return ans;
28    }
29};