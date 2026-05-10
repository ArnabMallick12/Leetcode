class Solution {
public:
    int fn(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ch1 = nums[i]+fn(i+2,nums,dp);
        int ch2 = fn(i+1,nums,dp);
        return dp[i] = max(ch1,ch2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return fn(0,nums,dp);

    }
};