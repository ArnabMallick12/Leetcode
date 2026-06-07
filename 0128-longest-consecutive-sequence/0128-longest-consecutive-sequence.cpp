class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums){
            st.insert(i);
        }
        int ans=0;
        int cnt=0;
        for(auto i : st){
            if(st.find(i-1)==st.end()){
                cnt =1;
                int x = i;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                ans =max(ans,cnt);
            }
        }
        return ans;
        }
};