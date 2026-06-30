class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for(int i = 0;i<nums.size();i++){
            if(st.empty() || st.top()!=nums[i]) {
                st.push(nums[i]);
                continue;
            }
            long long curr = nums[i];
            while(!st.empty() && curr==st.top()){
                curr += st.top();
                st.pop();
            }
            st.push(curr);
        }
        vector<long long> ans(st.size());
        for(int i = st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};