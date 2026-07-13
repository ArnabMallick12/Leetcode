class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& rooms) {
        vis[node] = 1;

        for (auto it : rooms[node]) {
            if (!vis[it]) {
                dfs(it, vis, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n, 0);

        dfs(0, vis, rooms);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};