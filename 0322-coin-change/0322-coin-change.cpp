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
        vector<vector<int>> dp(n,vector<int>(amount +1,1e9));
         for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int np = dp[i-1][j];
                int pick = 1e9;
                if(coins[i]<=j){
                    pick = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(np,pick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans == 1e9) return -1;
        return ans;
    }
};