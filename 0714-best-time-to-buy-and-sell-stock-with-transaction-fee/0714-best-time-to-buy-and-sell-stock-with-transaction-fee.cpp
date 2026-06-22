class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        int aheadbuy =0 , aheadnotbuy = 0;
        for(int i=n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                long long profit=0;
                if(buy){
                    profit = max(
                        -prices[i] + aheadnotbuy,
                        aheadbuy
                    );
                    aheadbuy = profit;
                }
                else{
                    profit = max(
                        +prices[i] + aheadbuy - fee,
                        aheadnotbuy
                    );
                    aheadnotbuy = profit;
                }
                // dp[i][buy] = profit;
            }
        }
        return aheadbuy;
    }
};