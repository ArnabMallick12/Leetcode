class Solution {
public:
    int fn(int i,vector<int>& prices, vector<int>& dp){
        if(i==prices.size()-1) return 0;
        if(dp[i] !=-1) return dp[i];
        int notbuy = fn(i+1,prices,dp);
        int buy = 0;
        for(int j = i+1;j<prices.size();j++){
            buy = max((prices[j]-prices[i]) + fn(j,prices,dp),buy);
        }
        return dp[i]=max(notbuy,buy);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        dp[n-1]  =0;
        for(int i = n-2;i>=0;i--){
            int notbuy = dp[i+1];
            int buy = 0;
            for(int j=i+1;j<n;j++){
                buy = max((prices[j]-prices[i] + dp[j]),buy);
            }
            dp[i] = max(notbuy,buy);
        }
        return dp[0];
    }
};