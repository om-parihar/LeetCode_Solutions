// Last updated: 8/31/2026, 4:30:26 PM
class Solution {
public:
    int count(int i, int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notake=count(i-1,amount,coins,dp);
        int take=0;
        if(coins[i]<=amount){
            take=count(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount] = take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return count(n-1,amount,coins,dp);
    }
};

class Solution1 {
public:
    int count(int i, int amount, vector<int>& coins){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            return 0;
        }
        int notake=count(i-1,amount,coins);
        int take=0;
        if(coins[i]<=amount){
            take=count(i,amount-coins[i],coins);
        }
        return take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return count(n-1,amount,coins);
    }
};