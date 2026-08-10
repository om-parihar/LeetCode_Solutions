// Last updated: 8/10/2026, 3:49:50 PM
1class Solution1 {
2public:
3    int count(int i, int j){
4        if(i==0 && j==0){
5            return 1;
6        }
7        if(i<0 || j<0) return 0;
8        int up=count(i,j-1);
9        int left=count(i-1,j);
10        return up+left;
11    }
12    int uniquePaths(int m, int n) {
13        int cnt=count(m-1,n-1);
14        return cnt;
15    }
16};
17
18
19class Solution2 {
20public:
21    int count(int i, int j, vector<vector<int>> &dp){
22        if(i==0 && j==0){
23            return 1;
24        }
25        if(i<0 || j<0) return 0;
26        if(dp[i][j]!=-1) return dp[i][j];
27        int up=count(i,j-1,dp);
28        int left=count(i-1,j,dp);
29        return dp[i][j]=up+left;
30    }
31    int uniquePaths(int m, int n) {
32        vector<vector<int>> dp(m,vector<int>(n,-1));
33        int cnt=count(m-1,n-1,dp);
34        return cnt;
35    }
36};
37
38
39class Solution {
40public:
41    int uniquePaths(int m, int n) {
42        vector<vector<int>> dp(m,vector<int>(n,-1));
43        dp[0][0]=1;
44        for(int i=0;i<m;i++){
45            for(int j=0;j<n;j++){
46                if(i==0 && j==0){
47                    dp[i][j]=1;
48                    continue;
49                }
50                int up=0,left=0;
51                if(i>0) up=dp[i-1][j];
52                if(j>0) left=dp[i][j-1];
53                dp[i][j]=up+left;
54            }
55        }
56        return dp[m-1][n-1];
57    }
58};