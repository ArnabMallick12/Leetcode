class Solution {
public:
    int fn(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e9;
        if(i == grid.size()-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = INT_MIN;
        for(int x=-1;x<=1;x++){
            for(int y = -1;y<=1;y++){
                maxi = max(maxi,fn(i+1,j1+x,j2+y,grid,dp));
            }
        }
        if(j1==j2) return dp[i][j1][j2] =  grid[i][j1] + maxi;
        else return dp[i][j1][j2] =  grid[i][j1] + grid[i][j2] + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  =grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return fn(0,0,m-1,grid,dp);
    }
};