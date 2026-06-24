class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen = 0;
        for(int i =0 ;i<s.size();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                bool valid = 1;
                for(auto it : freq){
                    if(it.second<k){
                        valid = false;
                        break;
                    }
                }
                if(valid) maxlen = max(maxlen,j-i+1);
                
            }
        }
        return maxlen;
    }
};