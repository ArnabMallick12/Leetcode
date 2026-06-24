class Solution {
public:
    int fn(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev] !=-1) return dp[i][prev];
        int len = fn(i+1,prev,nums,dp);
        if(prev == 0 || nums[i]>nums[prev-1]){
            len = max(len, 1+ fn(i+1,i+1,nums,dp));
        }
        return dp[i][prev] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]  = max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};