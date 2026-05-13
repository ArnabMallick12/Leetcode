class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int ,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int minv = INT_MAX;
        int ans=-1;
        for(auto it : mp){
            if(it.second.size()>=3){
                vector<int> temp = it.second;
                for(int i=0;i+2<temp.size();i++){
                    int value = abs(temp[i]-temp[i+1])+abs(temp[i+1]-temp[i+2])+abs(temp[i]-temp[i+2]);
                    if(value<minv){
                        ans = value;
                        minv = value;
                    }
                }
                
            }
        }
        return ans;
    }
};