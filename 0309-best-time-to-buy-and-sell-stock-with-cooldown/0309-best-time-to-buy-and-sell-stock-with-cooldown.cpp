class Solution {
public:
    int fn(int i, int buy, vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit  =0;
        if(buy){
            profit = max(
                -prices[i] + fn(i+1,0,prices,dp),
                fn(i+1,1,prices,dp)
            );
        }
        else{
            profit = max(
                +prices[i] + fn(i,1,prices,dp),
                fn(i+1,0,prices,dp)
            );
        }
        return dp[i][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // dp[n][1]=dp[n][0] =0;
        int notbuy =0 , buy = 0, nextahead =0 ;
        for(int i = n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit = 0;
                if(j){
                    profit = max(
                        -prices[i] + notbuy,
                        buy
                    );
                    nextahead = buy;
                    buy = profit;
                }
                else{
                    profit = max(
                        +prices[i] + nextahead,
                        notbuy
                    );
                    notbuy = profit;
                }
                // dp[i][j] = profit;
            }
        }
        // for(int i = 0;i<=n;i++){
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        // }

        return buy;
    }
};