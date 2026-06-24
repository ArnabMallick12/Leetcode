class Solution {
public:
    int fn(vector<int>& nums, int k){
        int l=0 , r=0;
        int ans = 0;
        int sum =0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            while(sum>k){
                sum -= nums[l]%2;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fn(nums,k) - fn(nums,k-1);
    }
};