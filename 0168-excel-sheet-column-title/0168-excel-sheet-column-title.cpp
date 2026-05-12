class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber>0){
            columnNumber--;
            int rem=columnNumber%26;
            char ch='A'+rem;
            s=ch+s;
            columnNumber/=26;
        }

        return s;
    }
};