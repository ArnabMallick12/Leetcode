class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string ans = "";
        int neg =0;
        if(num<0) {
            neg =1;
            num *= -1;
        }
        while(num>0){
            int rem  = num%7;
            char ch = '0' + (rem);
            ans = ch + ans;
            num/=7;
        }
        if(neg) ans = '-' + ans;
        return ans;
    }
};