class Solution {
public:
    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> NGE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> PGE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    long long subarraymins(vector<int>& nums){
        vector<int> nse = NSE(nums), pse= PSE(nums);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long f = left*right*1LL;
            long long val = f*nums[i];
            ans+=val;
        }
        return ans;
    }
    long long subarraymaxs(vector<int>& nums){
        vector<int> nge = NGE(nums), pge= PGE(nums);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            long long f = left*right*1LL;
            long long val = f*nums[i];
            ans+=val;
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (subarraymaxs(nums)-subarraymins(nums));
    }
};