class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans =0;
        int ls[3] = {-1,-1,-1};
        for(int i=0;i<s.size();i++){
            ls[s[i]-'a'] = i;
            ans+= 1 + min({ls[0],ls[1],ls[2]});
        }
        return ans;
    }
};