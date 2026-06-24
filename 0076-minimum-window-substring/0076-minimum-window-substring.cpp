class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l=0,r=0;
        int minlen = INT_MAX;
        int sti = -1;
        int cnt=0;
        int hash[256] = {0};
        for(char ch : t){
            hash[ch]++;
        }
        while(r<n){
            if(hash[s[r]]>0) {
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m){
                if(minlen>r-l+1){
                    minlen = r-l+1;
                    sti = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(sti == -1) return "";
        else return s.substr(sti,minlen);
    }
};