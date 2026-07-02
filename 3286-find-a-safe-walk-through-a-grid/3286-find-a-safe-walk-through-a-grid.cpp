class Solution {
public:
    bool dfs(int r, int c, int health,
             vector<vector<int>>& grid,
             vector<vector<int>>& best) {

        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return false;

        health -= grid[r][c];

        if (health <= 0)
            return false;

        if (r == grid.size() - 1 && c == grid[0].size() - 1)
            return true;

        if (best[r][c] >= health)
            return false;

        best[r][c] = health;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (dfs(nr, nc, health, grid, best))
                return true;
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> best(grid.size(),
                                 vector<int>(grid[0].size(), -1));

        return dfs(0, 0, health, grid, best);
    }
};