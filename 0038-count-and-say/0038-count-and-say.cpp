class Solution {
public:
    string RLE(string s){
        string ans;
        int sz = s.size();
        int cnt=1;
        for(int i=1;i<sz;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                ans += '0' + cnt;
                ans+=s[i-1];
                cnt=1;
            }
        }
        ans += '0' + cnt;
        ans+=s[sz-1];
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return RLE(countAndSay(n-1));
    }
};