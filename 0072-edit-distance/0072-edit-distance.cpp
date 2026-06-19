class Solution {
public:
    int fn(int i,int j , string word1, string word2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = fn(i-1,j-1,word1,word2,dp);
        }
        else{
           return dp[i][j] = 1+min(
                fn(i,j-1,word1,word2,dp),
            min(
                fn(i-1,j,word1,word2,dp),
                fn(i-1,j-1,word1,word2,dp)
            ));
        }
    }
    int minDistance(string word1, string word2) {
        int n =word1.size() , m= word2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0) ,curr(m+1,0);
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = i;
        // }
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1+ min(
                        prev[j],min(
                            prev[j-1],
                            curr[j-1]
                        )
                    );
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};