class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[(i+(nums.size()-((k+1)%nums.size()))+1)%nums.size()]);
            cout<<(i+k+1)%nums.size()<<" "<<endl;
            // cout<<ans[i-(k+1)]<<" ";
        }
        nums=ans;
        for(int i=0;i<nums.size();i++){
            cout<<ans[i]<<" ";
            
        }
    }
};