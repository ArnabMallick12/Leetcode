class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int temp =0;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                temp+=nums[i-1];
            }
            else{
                temp+=nums[i-1];
                ans = max(temp,ans);
                temp=0;
            }
        }
        if(n>1){
        if(nums[n-1]>nums[n-2] ) temp+=nums[n-1];}
        ans = max(temp,ans);
        return ans;
    }
};