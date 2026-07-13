class Solution {
public:
    void dfs(int i,int j,int &area , vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[i][j]=1;
        area++;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for(int x=0;x<4;x++){
            int nr = i + dr[x];
            int nc = j + dc[x];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,area,vis,grid);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area  =0;
                    dfs(i,j, area, vis , grid);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};