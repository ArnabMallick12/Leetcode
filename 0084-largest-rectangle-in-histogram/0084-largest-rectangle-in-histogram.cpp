class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans  =0;
        for(int i=0;i<=heights.size();i++){
            while(!st.empty() && (i==heights.size() || heights[st.top()]>=heights[i])){
                int h  = heights[st.top()];
                st.pop();

                int w;
                if(st.empty()) w  =i;
                else w = i - st.top()-1;
                ans= max(h*w,ans);
            }
            st.push(i);
        }
        return ans;
    }
};