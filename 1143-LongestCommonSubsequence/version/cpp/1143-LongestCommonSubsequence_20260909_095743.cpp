// Last updated: 9/9/2026, 9:57:43 AM
1class Solution {
2public:
3    int count(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
4        if(i==text1.size() || j==text2.size()){
5            return 0;
6        }
7        if(dp[i][j]!=-1) return dp[i][j];
8        if(text1[i]==text2[j]){
9            return dp[i][j]= 1+count(i+1,j+1,text1,text2,dp);
10        }
11        return dp[i][j]=max(count(i+1,j,text1,text2,dp),count(i,j+1,text1,text2,dp));
12    }
13    int longestCommonSubsequence(string text1, string text2) {
14        int n=text1.size();
15        int m=text2.size();
16        vector<vector<int>> dp(n,vector<int>(m,-1));
17        int ans = count(0,0,text1,text2,dp);
18        return ans;
19    }
20};