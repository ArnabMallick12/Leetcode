class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n==0 || m==0) return;

        vector<vector<int>> vis(n,vector<int>(m,0));

        // top & bottom row
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O') dfs(0,i,vis,board);
            if(!vis[n-1][i] && board[n-1][i]=='O') dfs(n-1,i,vis,board);
        }

        // left & right column
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O') dfs(i,0,vis,board);
            if(!vis[i][m-1] && board[i][m-1]=='O') dfs(i,m-1,vis,board);
        }

        // convert surrounded regions
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};