class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[i%n]>nums[st.top()]){
                mp[st.top()]  = nums[i%n];
                st.pop();
            }
            if(mp.find(i%n)==mp.end()) st.push(i%n);
        }
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        for(int i =0 ;i<n;i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};