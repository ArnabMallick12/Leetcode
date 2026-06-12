class Solution {
public:
    int fn(int i, int amount,vector<int>& coins , vector<vector<int>>& dp){
        if(amount ==0) return 0;
        if(i == coins.size()){
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int np = fn(i+1,amount,coins,dp);
        int pick = 1e9;
        if(coins[i]<=amount){
            pick = 1 + fn(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount] =  min(np,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount +1,-1));
        int ans = fn(0,amount,coins,dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};