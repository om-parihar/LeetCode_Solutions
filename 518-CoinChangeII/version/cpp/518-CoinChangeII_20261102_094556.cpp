// Last updated: 11/2/2026, 9:45:56 AM
1class Solution {
2public:
3    int count(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
4        if(i==coins.size()-1){
5            if(target%coins[i]==0) return 1;
6            return 0; 
7        }
8        if(dp[i][target]!=-1) return dp[i][target];
9        int notake=count(i+1,target,coins,dp);
10        int take=0;
11        if(coins[i]<=target){
12            take=count(i,target-coins[i],coins,dp);
13        }
14        return dp[i][target]=take+notake;
15    }
16    int change(int amount, vector<int>& coins) {
17        int n=coins.size();
18        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
19        return count(0,amount,coins,dp);
20    }
21};