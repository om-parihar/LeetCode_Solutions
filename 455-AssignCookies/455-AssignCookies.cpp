// Last updated: 8/15/2026, 7:47:22 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        int n=g.size();
5        int m=s.size();
6        sort(g.begin(),g.end());
7        sort(s.begin(),s.end());
8        int i=0,j=0;
9        while(i<n && j<m){
10            if(s[j]>=g[i]){
11                i++;
12            }
13            j++;
14        }
15        return i;
16    }
17};
18
19class Solution2 {
20public:
21    int count(int i, int j, vector<int>& g, vector<int>& s, vector<vector<int>>& dp){
22        if(j==s.size() || i==g.size()){
23            return 0;
24        }
25        if(dp[i][j]!=-1) return dp[i][j];
26        int notake=count(i,j+1,g,s,dp);
27        int take=0;
28        if(s[j]>=g[i]){
29            take=1+count(i+1,j+1,g,s,dp);
30        }
31        return dp[i][j] = max(take,notake);
32    }
33    int findContentChildren(vector<int>& g, vector<int>& s) {
34        int n=g.size();
35        int m=s.size();
36        sort(g.begin(),g.end());
37        sort(s.begin(),s.end());
38        vector<vector<int>> dp(n,vector<int>(m,-1));
39        return count(0,0,g,s,dp);
40    }
41};
42
43
44class Solution1 {
45public:
46    int count(int i, int j, vector<int>& g, vector<int>& s){
47        if(j==s.size() || i==g.size()){
48            return 0;
49        }
50        int notake=count(i,j+1,g,s);
51        int take=0;
52        if(s[j]>=g[i]){
53            take=1+count(i+1,j+1,g,s);
54        }
55        return max(take,notake);
56    }
57    int findContentChildren(vector<int>& g, vector<int>& s) {
58        int n=g.size();
59        int m=s.size();
60        sort(g.begin(),g.end());
61        sort(s.begin(),s.end());
62        return count(0,0,g,s);
63    }
64};