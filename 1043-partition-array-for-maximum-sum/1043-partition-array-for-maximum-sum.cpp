class Solution {
public:
    // int fn(int i , int k ,vector<int>& arr,vector<int> &dp){
    //     if(i == arr.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int maxAns = INT_MIN;
    //     int maxi = INT_MIN;
    //     int len =0;
    //     for(int j =i;j< min((int)arr.size(),i+k);j++){
    //         len++;
    //         maxi = max(maxi,arr[j]);
    //         int sum = len*maxi + fn(j+1,k,arr,dp);
    //         maxAns = max(maxAns,sum);
    //     }
    //     return dp[i] = maxAns;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i = n-1;i>=0;i--){
            int maxAns = INT_MIN;
            int maxi = INT_MIN;
            int len =0;
            for(int j =i;j< min(n,i+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};