class Solution {
public:
    int const MOD = 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int cnt=0;
        long long ans =1;
        int previdx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(previdx != -1){
                    int split =  i -previdx;
                    ans = (ans*split)%MOD;
                }
                previdx = i;
            }
        }
        if(previdx == -1) return 0;
        return ans;
        // cout<<cnt<<" "<<first<<" "<<second;
        // if(cnt ==1) return 1;
        // return second - first;
    }
};