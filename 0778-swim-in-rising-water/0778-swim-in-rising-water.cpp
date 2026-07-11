class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        vector<pair<int, int>> pos(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int t = 0; t < n * n; t++) {

            int r = pos[t].first;
            int c = pos[t].second;

            vis[r][c] = 1;

            int node = r * n + c;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    vis[nr][nc]) {

                    int adjNode = nr * n + nc;
                    ds.unite(node, adjNode);
                }
            }

            if (ds.find(0) == ds.find(n * n - 1))
                return t;
        }

        return -1;
    }
};