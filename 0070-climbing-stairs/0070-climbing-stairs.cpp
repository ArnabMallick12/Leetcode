class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return 1;
        // int dp[n+1];
        int prev1=1;
        int prev2=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans = prev1+prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
        
    }
};