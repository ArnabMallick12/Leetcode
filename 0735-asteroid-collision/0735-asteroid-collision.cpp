class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                int des = 0;
                while(!st.empty() && asteroids[st.top()]>0 && abs(asteroids[i])>=asteroids[st.top()] && des==0){
                    if(abs(asteroids[i])==asteroids[st.top()]) des=1;
                    st.pop();
                }
                if(!st.empty() && asteroids[st.top()]>=asteroids[i] && asteroids[st.top()]>0) {
                    des =1;
                }
                if(!des) st.push(i);
            }
            else{
                st.push(i);
            }
        }
        int n = st.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i] = asteroids[st.top()];
            st.pop();
        }
        return ans;
    }
};