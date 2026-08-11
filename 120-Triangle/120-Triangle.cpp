// Last updated: 8/11/2026, 5:37:18 PM
1class Solution1 {
2public:
3    int count(int i, int j, vector<vector<int>> &triangle){
4        if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
5        int down=triangle[i][j]+count(i+1,j,triangle);
6        int diag=triangle[i][j]+count(i+1,j+1,triangle);
7        return min(down,diag);
8    }
9    int minimumTotal(vector<vector<int>>& triangle) {
10        int n=triangle.size();
11        int cnt=count(0,0,triangle);
12        return cnt;
13    }
14};
15
16class Solution2 {
17public:
18    int count(int i, int j, vector<vector<int>> &triangle,vector<vector<int>> &dp){
19        if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
20        if(dp[i][j]!=-1) return dp[i][j];
21        int down=triangle[i][j]+count(i+1,j,triangle,dp);
22        int diag=triangle[i][j]+count(i+1,j+1,triangle,dp);
23        return dp[i][j]=min(down,diag);
24    }
25    int minimumTotal(vector<vector<int>>& triangle) {
26        int n=triangle.size();
27        int m=triangle[n-1].size();
28        vector<vector<int>> dp(n,vector<int>(m,-1));
29        int cnt=count(0,0,triangle,dp);
30        return cnt;
31    }
32};
33
34
35class Solution {
36public:
37    int minimumTotal(vector<vector<int>>& triangle) {
38        int n=triangle.size();
39        vector<vector<int>> dp(n,vector<int>(n,-1));
40        for(int i=0;i<n;i++){
41            dp[n-1][i]=triangle[n-1][i];
42        }
43        for(int i=n-2;i>=0;i--){
44            for(int j=i;j>=0;j--){
45                int down=triangle[i][j]+dp[i+1][j];
46                int diag=triangle[i][j]+dp[i+1][j+1];
47                dp[i][j]=min(down,diag);
48            }
49        }
50        return dp[0][0];
51    }
52};