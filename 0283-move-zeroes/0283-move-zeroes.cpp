class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans[cnt]=nums[i];
                cnt++;
            }
        }
        nums = ans;
    }
};