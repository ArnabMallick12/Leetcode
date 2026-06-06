class Solution {
public:
    int uniquePaths(int m, int n) {
        int steps = m+n-2;
        long long ans=1;
        int r = min(m-1,n-1);
        for(int i=0;i<r;i++){
            ans*=steps-i;
            ans/=i+1;
        }
        return ans;
    }
};