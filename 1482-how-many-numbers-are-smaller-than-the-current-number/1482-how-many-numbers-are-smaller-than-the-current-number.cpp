class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int arr[102]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        for(int i=1;i<102;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if (nums[i] == 0) {
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[nums[i]-1]);
            }
        }
        return ans;
    }
};