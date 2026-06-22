class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        int m = grid[0].size();
        // int ans =0 ;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        int dr[] = {-1,0,1,1,1,0,-1,-1};
        int dc[] = {-1,-1,-1,0,1,1,1,0};
        vector<vector<int>> vis(n,vector<int>(m,-1));
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            if(x==n-1 && y == m-1){
                    return d+1;
                }
            q.pop();
            for(int i=0;i<8;i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 &&  nx<n && ny>=0 && ny<m && grid[nx][ny]==0 && vis[nx][ny]==-1){
                    
        
                        vis[nx][ny]=1;
                        q.push({{nx,ny},d+1});
                    
                }
            }
        }
        return -1;
    }
};