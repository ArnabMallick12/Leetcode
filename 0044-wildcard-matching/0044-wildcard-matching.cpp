class Solution {
public:
    

    bool isallstar(string &p, int j) {
        for(int k = 0; k <= j; k++) {
            if(p[k] != '*') return false;
        }
        return true;
    }

    bool fn(int i, int j, string &s, string &p, vector<vector<int>>& dp) {

        if(i < 0 && j < 0) return true;

        if(i < 0 && j >= 0)
            return isallstar(p, j);

        if(j < 0 && i >= 0)
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = fn(i-1, j-1, s, p,dp);

        if(p[j] == '*')
            return dp[i][j] =
                fn(i, j-1, s, p,dp) ||
                fn(i-1, j, s, p,dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1,0) ,curr(m+1,0);
        prev[0] =1;
        for(int j=1;j<=m;j++){
            if(isallstar(p, j-1)){
                prev[j] =1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    curr[j] = prev[j-1];

                else if(p[j-1] == '*')
                     curr[j] = prev[j] || curr[j-1];
                else curr[j] = 0;
            }
            prev=curr;
        }

        return prev[m];
    }
};