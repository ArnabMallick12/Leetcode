class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];
            auto it = mp.find(req);
            if(it!=mp.end()){
                return {i,it->second};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};