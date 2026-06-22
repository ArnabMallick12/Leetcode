class Solution {
public:
    int fn(vector<int>& h){
        stack<int> st;
        int maxArea =0;
        h.push_back(0);
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[i]<h[st.top()]){
                int ht = h[st.top()];
                st.pop();
                if(st.empty()){
                    maxArea = max(maxArea, ht*(i));
                }
                else{
                    maxArea = max(maxArea, ht*(i-st.top()-1));
                }
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<int> h(m,0);
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    h[j]++;
                }
                else{
                    h[j]=0;
                }
            }
            ans= max(ans,fn(h));
        }
        return ans;
    }
};