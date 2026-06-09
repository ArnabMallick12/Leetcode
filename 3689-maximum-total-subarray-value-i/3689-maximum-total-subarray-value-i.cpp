class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return 0;
        // if(n==1) return nums[0]*k*1LL;
        sort(nums.begin(),nums.end());
        return (nums[n-1]-nums[0])*1LL*k;
    }
};