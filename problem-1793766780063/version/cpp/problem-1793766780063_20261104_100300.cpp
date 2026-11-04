// Last updated: 11/4/2026, 10:03:00 AM
1class Solution1 {
2public:
3    int count(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
4        if(i==text1.size() || j==text2.size()){
5            return 0;
6        }
7        if(dp[i][j]!=-1) return dp[i][j];
8        if(text1[i]==text2[j]){
9            return dp[i][j]=1+count(i+1,j+1,text1,text2,dp);
10        }
11        return dp[i][j]=max(count(i+1,j,text1,text2,dp),count(i,j+1,text1,text2,dp));
12    }
13    int longestCommonSubsequence(string text1, string text2) {
14        int n=text1.size();
15        int m=text2.size();
16        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
17        return count(0,0,text1,text2,dp);
18    }
19};
20
21
22class Solution{
23public:
24    int longestCommonSubsequence(string text1, string text2){
25        int n=text1.size();
26        int m=text2.size();
27        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
28        for(int i=0;i<n;i++) dp[i][0]=0;
29        for(int j=0;j<m;j++) dp[0][j]=0;
30        for(int i=1;i<=n;i++){
31            for(int j=1;j<=m;j++){
32                if(text1[i-1]==text2[j-1]){
33                    dp[i][j]=1+dp[i-1][j-1];
34                }
35                else{
36                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
37                }
38            }
39        }
40        return dp[n][m];
41    }
42};