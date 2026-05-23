class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fcnt =0;

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    fcnt++;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        int cnt=0;
        int tm =0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx<m && nx>=0 && ny<n && ny>=0 && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({{nx,ny},t+1});
                    cnt++;
                }
            }
        }
        if(fcnt!=cnt) return -1;
        return tm;

    }
};