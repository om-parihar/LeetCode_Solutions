// Last updated: 9/14/2026, 3:04:42 PM
1class Solution {
2public:
3    bool isPalindromic(string& s, int i, int j,vector<vector<int>>& dp){
4        if(i>=j) return true;
5        if(dp[i][j]!=-1) return dp[i][j];
6        if(s[i]!=s[j]) return false;
7        return dp[i][j] = isPalindromic(s,i+1,j-1,dp);
8    }
9    int countSubstrings(string s) {
10        int n=s.size();
11        int cnt=0;
12        vector<vector<int>> dp(n,vector<int>(n,-1));
13        for(int start=0;start<n;start++){
14            for(int end=start;end<n;end++){
15                if(isPalindromic(s,start,end,dp)) cnt++;
16            }
17        }
18        return cnt;
19    }
20};
21
22class Solution1 {
23public:
24    bool isPalindromic(string& s, int i, int j){
25        if(i>=j) return true;
26        if(s[i]!=s[j]) return false;
27        return isPalindromic(s,i+1,j-1);
28    }
29    int countSubstrings(string s) {
30        int n=s.size();
31        int cnt=0;
32        for(int start=0;start<n;start++){
33            for(int end=start;end<n;end++){
34                if(isPalindromic(s,start,end)) cnt++;
35            }
36        }
37        return cnt;
38    }
39};