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
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,0,nums,dp);
    }
};