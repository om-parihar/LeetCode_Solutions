// Last updated: 9/9/2026, 11:00:56 AM
1class Solution {
2public:
3    int solve(int i, int j, string& s, vector<vector<int>>& dp){
4        if(i>j) return 0;
5        if(dp[i][j]!=-1) return dp[i][j];
6        if(i==j) return dp[i][j] = 1;
7        if(s[i]==s[j]){
8            return dp[i][j] = 2+solve(i+1,j-1,s,dp);
9        }
10        return dp[i][j]=max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
11    }
12    int longestPalindromeSubseq(string s) {
13        int n=s.size();
14        vector<vector<int>> dp(n,vector<int>(n,-1));
15        int ans=solve(0,n-1,s,dp);
16        return ans;
17    }
18};