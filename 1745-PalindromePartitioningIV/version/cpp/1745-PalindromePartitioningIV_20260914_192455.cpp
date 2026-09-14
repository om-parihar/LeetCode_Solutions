// Last updated: 9/14/2026, 7:24:55 PM
1class Solution {
2public:
3    bool isPalindrome(string& s, int i, int j,vector<vector<int>>& dp){
4        if(i>=j) return true;
5        if(dp[i][j]!=-1) return dp[i][j];
6        if(s[i]!=s[j]) return false;
7        return dp[i][j] = isPalindrome(s,i+1,j-1,dp);
8    }
9    bool checkPartitioning(string s) {
10        int n=s.size();
11        vector<vector<int>> dp(n,vector<int>(n,-1));
12        for(int i=1;i<n-1;i++){
13            for(int j=i+1;j<n;j++){
14                if(isPalindrome(s,0,i-1,dp) && isPalindrome(s,i,j-1,dp) && isPalindrome(s,j,n-1,dp)){
15                    return true;
16                }
17            }
18        }
19        return false;
20    }
21};
22
23class Solution1 {
24public:
25    bool isPalindrome(string& s, int i, int j){
26        while(i<j){
27            if(s[i]!=s[j]) return false;
28            i++;
29            j--;
30        }
31        return true;
32    }
33    bool checkPartitioning(string s) {
34        int n=s.size();
35        for(int i=1;i<n-1;i++){
36            for(int j=i+1;j<n;j++){
37                if(isPalindrome(s,0,i-1) && isPalindrome(s,i,j-1) && isPalindrome(s,j,n-1)){
38                    return true;
39                }
40            }
41        }
42        return false;
43    }
44};