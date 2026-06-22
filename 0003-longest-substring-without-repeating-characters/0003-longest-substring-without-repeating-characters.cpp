class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int l=0;
        int r =0;
        int ans =0;
        while(r<s.size()){
            freq[s[r]]++;
            if(freq[s[r]]>1){
                while(freq[s[r]]>1){
                    freq[s[l]]--;
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};