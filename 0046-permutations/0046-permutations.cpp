class Solution {
public:
    void fn(vector<int>& nums,vector<int>& temp,vector<int>& used,vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==1) continue;
            used[i]=1;
            temp.push_back(nums[i]);
             fn(nums,temp,used,ans);
            temp.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(),0);
        fn(nums,temp,used,ans);
        return ans;
        
    }
};