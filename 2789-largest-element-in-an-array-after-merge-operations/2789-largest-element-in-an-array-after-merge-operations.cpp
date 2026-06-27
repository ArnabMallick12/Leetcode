class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long curr = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i]<=curr){
                curr+=nums[i];
            }
            else curr = nums[i];
        }
        return curr;
    }
};