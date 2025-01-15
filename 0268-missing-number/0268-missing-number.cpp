class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size()+1;i++){
            mp[i]++;
        }
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i :mp){
            cout<<i.first<<"-"<<i.second<<" ";
            if(i.second == 1){
                return i.first;
            }
        }
        return 0;
    }
};