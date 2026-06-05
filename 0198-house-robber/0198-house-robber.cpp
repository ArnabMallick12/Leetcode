class Solution {
public:
    int fn(int idx, vector<int>& nums,vector<int>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = fn(idx+2,nums,dp) + nums[idx];
        int ntake = fn(idx+1,nums,dp);
        return dp[idx] = max(take,ntake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        fn(0,nums,dp);
        return dp[0];
    }
};