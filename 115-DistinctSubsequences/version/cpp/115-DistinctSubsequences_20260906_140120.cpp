// Last updated: 9/6/2026, 2:01:20 PM
1class Solution {
2public:
3    int count(int i, int j, string &s, string &t, vector<vector<int>>& dp){
4        if(j==t.size()) return 1;
5        if(i==s.size()) return 0;
6        if(dp[i][j]!=-1) return dp[i][j];
7        int skip= count(i+1,j,s,t,dp);
8        int take=0;
9        if(s[i]==t[j]){
10            take = count(i+1,j+1,s,t,dp);
11        }
12        return dp[i][j]=take+skip;
13    }
14    int numDistinct(string s, string t) {
15        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
16        return count(0,0,s,t,dp);
17    }
18};
19
20class Solution2 {
21public:
22    void count(int i, string &s, string &t, int &cnt, string& temp){
23        if(temp==t){
24            cnt++;
25            return;
26        }
27        if(i==s.size()){
28            return;
29        }
30        for(int start=i;start<s.size();start++){
31            temp+=s[start];
32            count(start+1,s,t,cnt,temp);
33            temp.pop_back();
34        }
35    }
36    int numDistinct(string s, string t) {
37        int cnt=0;
38        string temp;
39        count(0,s,t,cnt,temp);
40        return cnt;
41    }
42};
43
44class Solution1 {
45public:
46    void count(int i, string &s, string &t, vector<string>& all, string& temp){
47        if(temp==t){
48            all.push_back(temp);
49            return;
50        }
51        if(i==s.size()){
52            return;
53        }
54        for(int start=i;start<s.size();start++){
55            temp+=s[start];
56            count(start+1,s,t,all,temp);
57            temp.pop_back();
58        }
59    }
60    int numDistinct(string s, string t) {
61        vector<string> all;
62        string temp;
63        count(0,s,t,all,temp);
64        return all.size();
65    }
66};