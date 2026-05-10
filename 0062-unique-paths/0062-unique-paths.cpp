class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = m+n-2;
        int t = min(m-1,n-1);
        long long ans=1;
        for(int i=0;i<t;i++){
            ans *=sum-i;
            ans/=i+1;
        }
        return ans;
    }
};