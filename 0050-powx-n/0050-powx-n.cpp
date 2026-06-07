class Solution {
public:
    double myPow(double x,int n) {
        long long N=n;
        if(N<0) {
            x=1/x;
            N=-1LL*N;
        }
        if(N==0) return 1;
        double ans=1;
        long long msb=log2(N);

        for(int i=msb;i>=0;i--) {
            ans=ans*ans;
            if((N>>i)&1) {
                ans=ans*x;
            }
        }

        return ans;
    }
};