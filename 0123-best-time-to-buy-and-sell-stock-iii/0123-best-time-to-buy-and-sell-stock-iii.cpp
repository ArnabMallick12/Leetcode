class Solution {
public:
    int fn(int i, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if (cap == 0)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + fn(i + 1, 0,cap, prices,dp),
                         fn(i + 1, 1,cap, prices,dp));
        } else {
            profit = max(+prices[i] + fn(i, 1,cap-1, prices,dp),
                         fn(i + 1, 0,cap, prices,dp));
        }
        return   dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> ahead(2,vector<int>(3,0)); 
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                for(int cap=1;cap<=2;cap++){
                    int profit = 0;
                    if(j){
                        profit = max(-prices[i] + ahead[0][cap],
                        ahead[1][cap]);
                    }
                    else{
                        profit = max(
                            +prices[i] + ahead[1][cap-1],
                            ahead[0][cap]                
                            );
                    }
                    ahead[j][cap] = profit;
                    // dp[i][j][cap] = profit;
                }
            }
        }
        return ahead[1][2];
    }
};