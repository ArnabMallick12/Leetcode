class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int psum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            psum=(psum+nums[i])%k;
            if(mp.find(psum)!=mp.end()){
                if((i-mp[psum])>1){
                    return true;
                }
            }
            else mp[psum] = i;
        }
        return false;
    }
};