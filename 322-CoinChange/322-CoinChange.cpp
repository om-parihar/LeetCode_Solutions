// Last updated: 8/15/2026, 8:13:53 PM
1class Solution {
2public:
3    int cnt(int i, int trg, vector<int>& coins, vector<vector<int>>& dp){
4        if(trg==0){
5            return 0;
6        }
7        if(i == 0) {
8        if(trg % coins[0] == 0)
9        return trg / coins[0];
10
11        return 1e9;
12        }
13        if(dp[i][trg]!=-1) return dp[i][trg];
14        int notake=cnt(i-1,trg,coins,dp);
15        int take=1e9;
16        if(coins[i]<=trg){
17            take=1+cnt(i,trg-coins[i],coins,dp);
18        }
19        return dp[i][trg] = min(take,notake);
20    }
21    int coinChange(vector<int>& coins, int amount) {
22        int n=coins.size();
23        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
24        int ans=cnt(n-1,amount,coins,dp);
25        if(ans == 1e9)
26            return -1;
27        return ans;
28    }
29};
30
31class Solution1 {
32public:
33    int cnt(int i, int trg, vector<int>& coins){
34        if(trg==0){
35            return 0;
36        }
37        if(i == 0) {
38        if(trg % coins[0] == 0)
39        return trg / coins[0];
40
41        return 1e9;
42        }
43        int notake=cnt(i-1,trg,coins);
44        int take=1e9;
45        if(coins[i]<=trg){
46            take=1+cnt(i,trg-coins[i],coins);
47        }
48        return min(take,notake);
49    }
50    int coinChange(vector<int>& coins, int amount) {
51        int n=coins.size();
52        int ans=cnt(n-1,amount,coins);
53        if(ans == 1e9)
54            return -1;
55        return ans;
56    }
57};