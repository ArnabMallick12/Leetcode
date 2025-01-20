class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [r, c] = pos[num];
            row[r]++;
            col[c]++;
            if (row[r] == n || col[c] == m) {
                return i;
            }
        }

        return -1;
    }
};
