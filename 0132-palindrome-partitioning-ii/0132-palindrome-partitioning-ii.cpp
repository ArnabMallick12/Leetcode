class Solution {
public:
    bool isPalindrome(int l,int r ,string &s, vector<vector<int>> &pal){
        // int i=0, j =s.size()-1;
        int i =l, j = r;
        if(pal[l][r]!=-1) return pal[l][r];
        while(i<j){
            if(s[i]!=s[j]) return pal[l][r] =  false;
            i++;
            j--;
        }
        return pal[l][r] = true;
    }
    // int fn(int i ,string s ,vector<int> &dp){
    //     if(i==s.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mini  = INT_MAX;
    //     string temp = "";
    //     for(int j=i;j<s.size();j++){
    //         temp+= s[j];
    //         if(isPalindrome(temp)){
    //             int cost = 1 + fn(j+1,s,dp);
    //             mini = min(mini,cost);
    //         }
    //     }
    //     return dp[i] = mini;
    // }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(s.size()+1,0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        for(int i = s.size()-1;i>=0;i--){
            int mini  = INT_MAX;
            string temp = "";
            for(int j=i;j<s.size();j++){
                temp+= s[j];
                if(pal[i][j]){
                    int cost = 1 + dp[j+1];
                    mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};