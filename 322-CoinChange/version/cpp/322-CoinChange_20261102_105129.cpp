// Last updated: 11/2/2026, 10:51:29 AM
1class Solution {
2public:
3    int count(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
4        if(amount==0) return 0;
5        if(i==0){
6            if(amount%coins[i]==0) return amount/coins[i];
7            return 1e9;
8        }
9        if(dp[i][amount]!=-1) return dp[i][amount];
10        int notake=count(i-1,amount,coins,dp);
11        int take=1e9;
12        if(coins[i]<=amount){
13            take=1+count(i,amount-coins[i],coins,dp);
14        }
15        return dp[i][amount]=min(take,notake);
16    }
17    int coinChange(vector<int>& coins, int amount) {
18        int n=coins.size();
19        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
20        int ans=count(n-1, amount, coins, dp);
21        if(ans==1e9) return -1;
22        return ans;
23    }
24};