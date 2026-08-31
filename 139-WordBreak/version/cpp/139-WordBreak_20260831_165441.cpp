// Last updated: 8/31/2026, 4:54:41 PM
1class Solution {
2public:
3    bool solve(int i, string &s, unordered_set<string> &st,vector<int> &dp){
4        if(i==s.size()) return true;
5        if(dp[i]!=-1) return dp[i];
6        for(int j=i;j<s.size();j++){
7            string temp=s.substr(i,j-i+1);
8            if(st.count(temp)){
9                if(solve(j+1,s,st,dp)){
10                    return dp[i]=true;
11                }
12            }
13        }
14        return dp[i]=false;
15    }
16    bool wordBreak(string s, vector<string>& wordDict) {
17        int n=s.size();
18        vector<int> dp(n+1,-1);
19        unordered_set<string> st(wordDict.begin(),wordDict.end());
20        return solve(0,s,st,dp);    
21    }
22};
23
24class Solution1 {
25public:
26    bool wordBreak(string s, vector<string>& wordDict) {
27        int n=s.size();
28        unordered_set<string> st(wordDict.begin(),wordDict.end());
29        vector<bool> dp(n+1,false);
30        dp[0]=true;
31        for(int i=1;i<=n;i++){
32            for(int j=0;j<i;j++){
33                if(dp[j] && st.count(s.substr(j,i-j))){
34                    dp[i]=true;
35                    break;
36                }
37            }
38        }
39        return dp[n];
40    }
41};