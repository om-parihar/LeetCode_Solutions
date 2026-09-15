// Last updated: 9/15/2026, 4:36:43 PM
1class Solution {
2public:
3    bool isPalindrome(string& s, int i, int j){
4        if(i>=j) return true;
5        if(s[i]!=s[j]) return false;
6        return isPalindrome(s,i+1,j-1);
7    }
8    int solve(string& s, int i, int k,vector<vector<int>>& dp){
9        if(i>=s.size()) return 0;
10        if(dp[i][k]!=-1) return dp[i][k];
11        int ans=solve(s,i+1,k,dp);
12        for(int j=i+k-1;j<s.size();j++){
13            if(isPalindrome(s,i,j)){
14                ans=max(ans,1+solve(s,j+1,k,dp));
15            }
16        }
17        return dp[i][k] = ans;
18    }
19    int maxPalindromes(string s, int k) {
20        int n=s.size();
21        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
22        return solve(s,0,k,dp);
23    }
24};