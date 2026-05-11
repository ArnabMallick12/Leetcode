class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths = (m-1)+(n-1);
        long long ans = 1;
        int steps = min(m-1,n-1);
        for(int i=1;i<=steps;i++){
            ans*=paths;
            ans/=i;
            paths--;
        }
        return ans;
    }
};