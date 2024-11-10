class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = sqrt(c);
        while(a<=b){
            long long ans = a*a + b*b;
            if (ans==c) return true;
            else if (ans<c) a++;
            else b--;
        }
        return false;
    }
};