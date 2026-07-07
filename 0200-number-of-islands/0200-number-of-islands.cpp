class Solution {
public:
    void dfs(int i , int j, vector<vector<char>>& grid , vector<vector<int>>& vis){
        if(i < 0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if(vis[i][j]) return;
        if(grid[i][j] !='1') return;
        vis[i][j] = 1;
        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};
        for(int x=0;x<4;x++){
            int nr = i + dr[x];
            int nc = j + dc[x];
             dfs(nr,nc,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};