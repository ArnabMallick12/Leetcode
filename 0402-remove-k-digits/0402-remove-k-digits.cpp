class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && num[i]=='0') continue;
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans=="") return "0";
        return ans;
    }
};