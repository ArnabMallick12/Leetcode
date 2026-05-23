class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> win;
        for(int i=0;i<nums.size();i++){
            if(!win.empty() && win.front()==i-k){
                win.pop_front();
            }
            while(!win.empty() && nums[win.back()]<=nums[i]){
                win.pop_back();
            }
            win.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[win.front()]);
            }
        }
        return ans;
    }
};