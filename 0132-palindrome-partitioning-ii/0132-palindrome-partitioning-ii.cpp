class Solution {
public:
    bool isPalindrome(int l,int r ,string &s, vector<vector<int>> &pal){
        // int i=0, j =s.size()-1;
        int i =l, j = r;
        if(pal[l][r]!=-1) return pal[i][j];
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
        vector<int> dp(s.size()+1,0);
        vector<vector<int>> pal(s.size(),vector<int>(s.size(),-1));
        for(int i = s.size()-1;i>=0;i--){
            int mini  = INT_MAX;
            string temp = "";
            for(int j=i;j<s.size();j++){
                temp+= s[j];
                if(isPalindrome(i,j,s,pal)){
                    int cost = 1 + dp[j+1];
                    mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};