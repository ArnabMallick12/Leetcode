class Solution {
public:
    void fn(int idx,vector<int>& candidates, int target, int sum, vector<int>& temp,vector<vector<int>>& ans ){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(sum+candidates[i]<=target) {
                temp.push_back(candidates[i]);
                fn(i,candidates,target,sum+candidates[i],temp,ans);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fn(0,candidates,target,0,temp,ans);
        return ans;
    }
};