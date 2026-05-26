class Solution {
public:
    int MOD = 1000000000+7;
    vector<int> NSE( vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE( vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        vector<int> nse = NSE(arr), pse = PSE(arr);
        for(int i=0;i<arr.size();i++){
            int left = i - pse[i];
            int right = nse[i]-i;
            long long f = left*right*1LL;
            int val = (f*arr[i])%MOD;
            ans = (ans+val)%MOD;
        }
        return ans;
    }
};