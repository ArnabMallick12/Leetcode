class Solution {
public:
    void dfs(int r ,int c ,int original , int color, vector<vector<int>>& image , vector<vector<int>>& vis){
        vis[r][c]=1;
        image[r][c] = color;
        int dr[] = {0,-1,1,0};
        int dc[] = {-1,0,0,1};
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && image[nr][nc] == original && !vis[nr][nc]){
                dfs(nr,nc,original,color,image,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int original = image[sr][sc];
        if (original == color) return image;
        vector<vector<int>> vis(m,vector<int>(n,0));
        dfs(sr,sc,original,color,image,vis);
        return image;
    }
};