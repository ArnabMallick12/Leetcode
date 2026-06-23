class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=0,maxfreq =0;
        unordered_map<char,int> freq;
        while(r<s.size()){
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);
            while((r-l+1) - maxfreq > k){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};