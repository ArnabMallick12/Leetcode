class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int > temp;
        temp.push_back(nums[0]);
        for(int i : nums){
            if(temp.back()<i){
                temp.push_back(i);
            }
            else{
                int ind  = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
                temp[ind] = i;
            }
        }
        return temp.size();
    }
};