class Solution {
public:
    int fn(int i,vector<int>& prices,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1 ) return dp[i];
        int maxi = 0;
        for(int j=i+1;j<prices.size();j++){
            maxi = max(maxi, prices[j]-prices[i]);
        }
        return dp[i] = max(maxi, fn(i-1,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minp  =  INT_MAX;
        int mp  =0;
        for(int i :prices){
            minp = min(i,minp);
            int p = i - minp;
            mp = max(mp,p);
        }
        return mp;
    }
};