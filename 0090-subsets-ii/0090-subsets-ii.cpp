class Solution {
public:
    void fn(int ind, vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans){
        if(ind == arr.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[ind]);
        fn(ind+1,curr,arr,ans);
        curr.pop_back();
        int nxt = ind+1;
        while(nxt<arr.size() && arr[nxt]==arr[ind]) nxt++;
        fn(nxt,curr,arr,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        fn(0,curr,nums,ans);
        return ans;
    }
};