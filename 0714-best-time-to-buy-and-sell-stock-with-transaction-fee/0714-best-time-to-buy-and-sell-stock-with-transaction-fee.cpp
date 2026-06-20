class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // dp[n][1]=dp[n][0] =0;
        int notbuy =0 , buy = 0;
        for(int i = n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit = 0;
                if(j){
                    profit = max(
                        -prices[i] + notbuy,
                        buy
                    );
                    buy = profit;
                }
                else{
                    profit = max(
                        +prices[i] + buy - fee,
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