// Last updated: 8/18/2026, 8:03:26 PM
1class Solution {
2public:
3    int count(int i, int amount, vector<int>& coins,vector<vector<int>> &dp){
4        if(i==0){
5            if(amount%coins[i]==0) return 1;
6            return 0;
7        }
8        if(dp[i][amount]!=-1) return dp[i][amount];
9        int notake=count(i-1,amount,coins,dp);
10        int take=0;
11        if(coins[i]<=amount){
12            take=count(i,amount-coins[i],coins,dp);
13        }
14        return dp[i][amount] = take+notake;
15    }
16    int change(int amount, vector<int>& coins) {
17        int n=coins.size();
18        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
19        return count(n-1,amount,coins,dp);
20    }
21};
22
23class Solution1 {
24public:
25    int count(int i, int amount, vector<int>& coins){
26        if(i==0){
27            if(amount%coins[i]==0) return 1;
28            return 0;
29        }
30        int notake=count(i-1,amount,coins);
31        int take=0;
32        if(coins[i]<=amount){
33            take=count(i,amount-coins[i],coins);
34        }
35        return take+notake;
36    }
37    int change(int amount, vector<int>& coins) {
38        int n=coins.size();
39        return count(n-1,amount,coins);
40    }
41};