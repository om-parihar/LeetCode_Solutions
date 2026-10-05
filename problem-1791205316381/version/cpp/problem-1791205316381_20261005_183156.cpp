// Last updated: 10/5/2026, 6:31:56 PM
1class Solution {
2public:
3    int count(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
4        if(i>=text1.size() || j>=text2.size()) return 0;
5        if(dp[i][j]!=-1) return dp[i][j];
6        if(text1[i]==text2[j]){
7            return dp[i][j]= 1+count(i+1,j+1,text1,text2,dp);
8        }
9        return dp[i][j]= max(count(i,j+1,text1,text2,dp),count(i+1,j,text1,text2,dp));
10    }
11    int longestCommonSubsequence(string text1, string text2) {
12        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
13        return count(0,0,text1,text2,dp);
14    }
15};