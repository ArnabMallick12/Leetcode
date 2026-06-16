class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char ch : s){
            if(ch>='a' && ch<='z'){
                ans += ch;
            }
            else if(ans == "") continue;
            if(ch == '*'){
                ans.pop_back();
            }
            else if(ch == '#'){
                ans += ans;
            }
            else if( ch=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};