class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& board){
        int n = board.size();
        int m = board[0].size();

        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,vis,board);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        if(n==0 || m==0) return 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        // top & bottom row
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1) dfs(0,i,vis,grid);
            if(!vis[n-1][i] && grid[n-1][i]==1) dfs(n-1,i,vis,grid);
        }

        // left & right column
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1) dfs(i,0,vis,grid);
            if(!vis[i][m-1] && grid[i][m-1]==1) dfs(i,m-1,vis,grid);
        }

        // convert surrounded regions
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};


    
