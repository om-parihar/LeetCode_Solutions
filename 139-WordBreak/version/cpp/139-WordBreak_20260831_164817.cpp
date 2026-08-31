// Last updated: 8/31/2026, 4:48:17 PM
1class Solution {
2public:
3    bool wordBreak(string s, vector<string>& wordDict) {
4        int n=s.size();
5        unordered_set<string> st(wordDict.begin(),wordDict.end());
6        vector<bool> dp(n+1,false);
7        dp[0]=true;
8        for(int i=1;i<=n;i++){
9            for(int j=0;j<i;j++){
10                if(dp[j] && st.count(s.substr(j,i-j))){
11                    dp[i]=true;
12                    break;
13                }
14            }
15        }
16        return dp[n];
17    }
18};