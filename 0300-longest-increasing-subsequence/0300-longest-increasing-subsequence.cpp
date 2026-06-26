class Solution {
public:
    int fn(int ind , int prev , vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int len = fn(ind+1,prev,nums,dp); // not pick
        if(prev == 0 || nums[ind]>nums[prev-1]){ //condition if can pick indth element
            len = max(len,fn(ind+1,ind+1,nums,dp)+1); //pick
        }
        return dp[ind][prev] =  len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,0,nums,dp);
    }
};