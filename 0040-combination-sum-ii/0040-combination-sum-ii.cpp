class Solution {
public:
    void fn(int ind, int t, vector<int> &curr, vector<int> &arr,vector<vector<int>> &ans){
        if(t == 0){
            ans.push_back(curr);
            return;
        }
        if(ind == arr.size() || t < 0) return;
        if(arr[ind]<=t){
            curr.push_back(arr[ind]);
            fn(ind+1,t-arr[ind],curr,arr,ans);
            curr.pop_back();
        }
        int nxt = ind+1;
        while(nxt<arr.size() && arr[nxt]==arr[ind]) nxt++;
        fn(nxt,t,curr,arr,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        fn(0,target,curr,candidates,ans);
        return ans;

    }
};