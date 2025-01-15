class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minele = prices[0];
        int maxele = prices[0];
        int maxprofit =0;
        for(int i=1;i<prices.size();i++){
            if (prices[i]<minele){
                minele = prices[i];
                maxele = prices[i];
            }
            if(prices[i]>maxele){
                maxele = prices[i];
            }
            if((maxele - minele)>maxprofit){
                maxprofit = maxele - minele;
            }
        }
        return maxprofit;
    }
};