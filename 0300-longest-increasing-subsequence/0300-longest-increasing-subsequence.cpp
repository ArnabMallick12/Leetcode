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
        vector<int> prev(n+1,0) , curr(n,0);
        for(int i =n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int len  = prev[j+1];
                if(j==-1 || nums[i]>nums[j]) len = max(len,1+prev[i+1]);
                curr[j+1] = len;
            }
            prev = curr;
        }
        return curr[0];
    }
};