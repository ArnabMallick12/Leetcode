class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = -1;
        long long incSum = nums[0];
        long long sum =nums[0];

        for(int i=1;i<n-1;i++){
            if(peak == -1){
                incSum += nums[i];
            }
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) peak = i;
            sum+=nums[i];
        }
        sum+=nums[n-1];
        long long decSum = sum - incSum + nums[peak];
        cout<<incSum<<" "<<decSum;
        if(incSum>decSum) return 0;
        else if(decSum>incSum) return 1;
        else return -1;
    }
};