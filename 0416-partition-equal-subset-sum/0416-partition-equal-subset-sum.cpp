class Solution {
public:
    int fn(int i, int target,vector<int>& nums,vector<vector<int>>& dp ){
        if(target==0) return true;
        if(i == nums.size()-1) return nums[i] == target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notpick  = fn(i+1,target,nums,dp);
        bool pick = false;
        if(nums[i]<=target) pick = fn(i+1,target-nums[i],nums,dp);
        return dp[i][target] =  notpick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        for(int i: nums){
            totsum+=i;
        }
        if(totsum%2==1) return false;
        int n = nums.size();
        int target = totsum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return fn(0,target,nums,dp);
    }
};