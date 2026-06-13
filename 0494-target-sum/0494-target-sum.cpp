class Solution {
public:
    int fn(int i,int target,vector<int>& nums){
        if(i == nums.size()) {
            if(target==0) return 1;
            return 0;
        }

        int neg = fn(i+1,target - nums[i],nums);
        int pos = fn(i+1,target+nums[i],nums);
        return neg+pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return fn(0,target,nums);
    }
};