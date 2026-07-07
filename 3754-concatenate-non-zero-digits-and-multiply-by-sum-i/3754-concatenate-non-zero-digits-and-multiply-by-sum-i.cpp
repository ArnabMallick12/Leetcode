class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans =0 ;
        long long sum  =0;
        int i =0 ;
        while(n){
            int digit = n%10;
            if(digit) {
                ans += digit*pow(10,i);
                i++;
            }
            sum+=digit;
            n/=10;
        }
        return ans*sum;
    }
};