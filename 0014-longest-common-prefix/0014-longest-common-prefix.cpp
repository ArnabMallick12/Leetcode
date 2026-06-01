class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        sort(strs.begin(),strs.end());
        string s1 =strs.front();
        string s2 = strs.back();
        int minlen = min(s1.length(),s2.length());
        int i=0;
        while(i<minlen && s1[i]==s2[i]){
            ans += s1[i];
            i++;
        }
        return ans;
    }
};