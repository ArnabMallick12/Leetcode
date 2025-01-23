class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int r1 = 0, r2 = m - 1, c1 = 0, c2 = n - 1;

        while (ans.size() < m * n) {
            for (int i = c1; i <= c2 && ans.size() < m * n; i++) {
                ans.push_back(matrix[r1][i]);
            }
            for (int i = r1 + 1; i <= r2 && ans.size() < m * n; i++) {
                ans.push_back(matrix[i][c2]);
            }
            for (int i = c2 - 1; i >= c1 && ans.size() < m * n; i--) {
                ans.push_back(matrix[r2][i]);
            }
            for (int i = r2 - 1; i > r1 && ans.size() < m * n; i--) {
                ans.push_back(matrix[i][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }

        return ans;
    }
};