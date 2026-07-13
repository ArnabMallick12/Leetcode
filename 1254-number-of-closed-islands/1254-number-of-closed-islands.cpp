class Solution {
public:
    void dfs(int i,int j , vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[i][j]=1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for(int x=0;x<4;x++){
            int nr = i + dr[x];
            int nc = j + dc[x];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==0 && !vis[nr][nc]){
                dfs(nr,nc,vis,grid);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0] ==0 &&  !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][n-1] ==0 && !vis[i][n-1]){
                dfs(i,n-1,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[0][i] ==0 &&  !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[m-1][i] ==0 && !vis[m-1][i]){
                dfs(m-1,i,vis,grid);
            }
        }

        int ans =0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};